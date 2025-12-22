#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>

const double PLANE_MASS = 70000.0;
const double WING_AREA = 113.0;
const double NOMINAL_THRUST = 2 * 137200.0;
const double GRAVITY = 9.81;
const double INITIAL_ALT = 400.0;
const double FINAL_ALT = 6500.0;
const double INITIAL_V = 310.0 / 3.6;
const double FINAL_V = 550.0 / 3.6;
const double MAX_THRUST_RATIO = 0.9;
const double MAX_CLIMB_DEG = 15.0;
const double MAX_VERTICAL_SPEED = 8.0;
const int DELTA_H = 250;
const double DEG2RAD = 57.3;

class CSVExporter {
    std::ofstream file;
public:
    CSVExporter(const std::string& fname) {
        file.open(fname);
        if (!file.is_open()) throw std::runtime_error("Cannot open file");
    }
    void writeHeader(const std::vector<std::string>& hdr) {
        for (size_t i = 0; i < hdr.size(); ++i) {
            file << hdr[i];
            if (i + 1 < hdr.size()) file << ",";
        }
        file << "\n";
    }
    void writeRow(const std::vector<double>& row) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << std::setprecision(6) << row[i];
            if (i + 1 < row.size()) file << ",";
        }
        file << "\n";
    }
};

class Atmosphere {
    std::vector<double> alt{ 0,500,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000 };
    std::vector<double> temp{ 288.15,284.9,281.651,275.154,268.659,262.166,255.676,249.187,242.7,236.215,229.733,223.252 };
    std::vector<double> pres{ 1.01325e5,9.54613e4,8.98763e4,7.95014e4,7.01212e4,6.16604e4,5.40483e4,4.72176e4,4.11051e4,3.56516e4,3.08007e4,2.64999e4 };
    std::vector<double> dens{ 1.22500,1.16727,1.11166,1.00655,0.909254,0.819347,0.736429,0.660111,0.590018,0.526783,0.467063,0.413510 };
    std::vector<double> sound{ 340.294,338.37,336.435,332.532,328.584,324.589,320.545,316.452,312.306,308.105,303.848,299.532 };

    double interp(double h, const std::vector<double>& vals) const {
        if (h <= alt.front()) return vals.front();
        if (h >= alt.back()) return vals.back();
        for (size_t i = 0; i < alt.size() - 1; i++) {
            if (h >= alt[i] && h <= alt[i + 1]) {
                double t = (h - alt[i]) / (alt[i + 1] - alt[i]);
                return vals[i] + t * (vals[i + 1] - vals[i]);
            }
        }
        return vals.front();
    }
public:
    double density(double h) const { return interp(h, dens); }
    double pressure(double h) const { return interp(h, pres); }
    double soundSpeed(double h) const { return interp(h, sound); }
    double mach(double v, double h) const { return v / soundSpeed(h); }
};

struct StatePoint {
    double t;
    double alt;
    double v;
};

class Aircraft {
    Atmosphere atm;
    double cx0 = 0.0275, k = 0.05, cyMax = 1.0;
public:
    double mass = PLANE_MASS;
    double thrust = NOMINAL_THRUST * MAX_THRUST_RATIO;

    double liftCoeff(double alpha) const {
        if (alpha < 0) alpha = 0;
        if (alpha > 15) alpha = 15;
        double cy = 0.25 + 0.08 * alpha;
        return std::min(cy, cyMax);
    }

    double dragCoeff(double cl) const { return cx0 + k * cl * cl; }

    double lift(double v, double h, double alpha) const {
        double rho = atm.density(h);
        return 0.5 * rho * WING_AREA * v * v * liftCoeff(alpha);
    }

    double drag(double v, double h, double alpha) const {
        double rho = atm.density(h);
        return 0.5 * rho * WING_AREA * v * v * dragCoeff(liftCoeff(alpha));
    }

    double availableThrust(double h) const {
        return thrust * pow(atm.pressure(h) / atm.pressure(0), 0.7);
    }

    double climbAngle(double h, double v) const {
        double p = availableThrust(h);
        double q = 0.5 * atm.density(h) * v * v;
        return std::min((p - q * dragCoeff(liftCoeff(0)) * WING_AREA) / (mass * GRAVITY), MAX_CLIMB_DEG / DEG2RAD);
    }
};

class TrajectorySolver {
public:
    std::vector<StatePoint> solve(Aircraft& ac) {
        int N = (FINAL_ALT - INITIAL_ALT) / DELTA_H;
        double dV = (FINAL_V - INITIAL_V) / N;
        std::vector<double> H(N + 1), V(N + 1);
        for (int i = 0; i <= N; i++) { H[i] = INITIAL_ALT + i * DELTA_H; V[i] = INITIAL_V + i * dV; }

        std::vector<std::vector<double>> time(N + 1, std::vector<double>(N + 1, 1e9));
        std::vector<std::vector<int>> prevI(N + 1, std::vector<int>(N + 1, -1));
        std::vector<std::vector<int>> prevJ(N + 1, std::vector<int>(N + 1, -1));
        time[0][0] = 0;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (time[i][j] >= 1e9) continue;
                double altCur = H[i], vCur = V[j];

                if (j < N) { // ускорение
                    double vNext = V[j + 1];
                    double avgV = (vCur + vNext) / 2;
                    double q = 0.5 * ac.availableThrust(altCur) * avgV * avgV;
                    double dt = (vNext - vCur) / ((ac.availableThrust(altCur) - q) / PLANE_MASS);
                    double newTime = time[i][j] + dt;
                    if (newTime < time[i][j + 1]) {
                        time[i][j + 1] = newTime;
                        prevI[i][j + 1] = i;
                        prevJ[i][j + 1] = j;
                    }
                }

                if (i < N) { // подъем
                    double altNext = H[i + 1];
                    double climbVel = ac.climbAngle(altCur, vCur) * vCur;
                    if (climbVel > MAX_VERTICAL_SPEED) climbVel = MAX_VERTICAL_SPEED;
                    double dt = (altNext - altCur) / climbVel;
                    double newTime = time[i][j] + dt;
                    if (newTime < time[i + 1][j]) {
                        time[i + 1][j] = newTime;
                        prevI[i + 1][j] = i;
                        prevJ[i + 1][j] = j;
                    }
                }
            }
        }

        std::vector<StatePoint> traj;
        int ci = N, cj = N;
        while (ci >= 0 && cj >= 0) {
            traj.push_back({ time[ci][cj],H[ci],V[cj] });
            int pi = prevI[ci][cj], pj = prevJ[ci][cj];
            if (pi == -1) break;
            ci = pi; cj = pj;
        }
        std::reverse(traj.begin(), traj.end());
        return traj;
    }

    void plotTrajectory(const std::vector<StatePoint>& traj) {
        FILE* gp = _popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persist", "w");
        if (!gp) { std::cerr << "Cannot open gnuplot\n"; return; }

        fprintf(gp, "set terminal wxt size 1200,900 font 'Arial,12'\n");
        fprintf(gp, "set multiplot layout 3,1 title 'Aircraft Trajectory'\n");

        // 1. Высота от времени
        fprintf(gp, "set title 'Altitude vs Time'\nset xlabel 'Time [s]'\nset ylabel 'Altitude [m]'\nset grid\n");
        fprintf(gp, "plot '-' with lines lw 2 lc 'blue' title 'Altitude'\n");
        for (auto& p : traj) fprintf(gp, "%f %f\n", p.t, p.alt);
        fprintf(gp, "e\n");

        // 2. Скорость от времени
        fprintf(gp, "set title 'Velocity vs Time'\nset xlabel 'Time [s]'\nset ylabel 'Velocity [km/h]'\nset grid\n");
        fprintf(gp, "plot '-' with lines lw 2 lc 'red' title 'Velocity'\n");
        for (auto& p : traj) fprintf(gp, "%f %f\n", p.t, p.v * 3.6);
        fprintf(gp, "e\n");

        // 3. Высота от скорости
        fprintf(gp, "set title 'Altitude vs Velocity'\nset xlabel 'Velocity [km/h]'\nset ylabel 'Altitude [m]'\nset grid\n");
        fprintf(gp, "plot '-' with lines lw 2 lc 'green' title 'Altitude'\n");
        for (auto& p : traj) fprintf(gp, "%f %f\n", p.v * 3.6, p.alt);
        fprintf(gp, "e\n");

        fprintf(gp, "unset multiplot\n");
        fflush(gp);
        std::cout << "Close Gnuplot window to continue\n";
        std::cin.get();
        _pclose(gp);
    }

};

int main() {
    try {
        Aircraft plane;
        TrajectorySolver solver;
        auto traj = solver.solve(plane);

        CSVExporter csv("trajectory.csv");
        csv.writeHeader({ "time_s","altitude_m","velocity_ms" });
        for (auto& p : traj) csv.writeRow({ p.t,p.alt,p.v });

        solver.plotTrajectory(traj);

    }
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }
}
