#include <iostream>
using namespace std;
class Aircraft
{
protected:
    double mass;
    double x, y, z;
    double vx, vy, vz;
public:
   void updatePosition(double dt) {
        x += dt * vx;
        y += dt * vy;
        z += dt * vz;
        }
   Aircraft(double m = 10000, double Vx, double Vy, double Vz) {
       mass = m;
       vx = Vx;
       vy = Vy;
       vz = Vz;
   }
    ~Aircraft()
   {
       cout << "Aircraft deleted";
   }
    virtual  void printStatus() const {
        cout << x << y << z;
    }
};
class JetAircraft : public Aircraft {
private:
    double thrust;
    double Cd;
    double S;
    double rho;
    double fuel;
    double g;
public:
    double  coumputeDrag(double v) {
        return 0.5*rho *v * v*Cd;
    }
    void simulateStep(double dt)
    {
        vx += (thrust - coumputeDrag(vx))/mass * dt;
        vy += (coumputeDrag(vy)*S-mass*g)/mass * dt;
        updatePosition(dt);
    }
     void printStatus () const override {
         cout << x << y << z << vx << vy << vz;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

