
﻿#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    double x;
    double y;
    double z;
};

class Rocket {
private:
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;

public:
    Rocket(double vx0, double vy0, double vz0)
        : x(0.0), y(0.0), z(0.0), vx(vx0), vy(vy0), vz(vz0) {
    }

    void updatePosition(double dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    void changeVelocity(double dvx, double dvy, double dvz) {
        vx += dvx;
        vy += dvy;
        vz += dvz;
    }

    Point getPosition() const {
        Point p;
        p.x = x;
        p.y = y;
        p.z = z;
        return p;
    }
};

int main() {
    vector<Rocket> squad;
    squad.reserve(5);

    squad.push_back(Rocket(10, 0, 50));
    squad.push_back(Rocket(15, -5, 40));
    squad.push_back(Rocket(12, 3, 45));
    squad.push_back(Rocket(8, 2, 60));
    squad.push_back(Rocket(20, -2, 30));

    vector< vector<Point> > trajectories(5);

    double dt = 1.0;
    double T = 10.0;

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); i++) {
            squad[i].updatePosition(dt);
            trajectories[i].push_back(squad[i].getPosition());
        }
    }

    cout << fixed << setprecision(2);
    cout << "Final rocket positions:" << endl;

    for (size_t i = 0; i < squad.size(); i++) {
        Point p = squad[i].getPosition();
        cout << "Rocket " << i + 1 << ": ";
        cout << "x = " << p.x << ", y = " << p.y << ", z = " << p.z << endl;
    }

    return 0;
}
