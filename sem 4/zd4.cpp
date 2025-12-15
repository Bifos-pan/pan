#include <iostream>
using namespace std;
class Gyroscope
{
private:
    double angularVelocity;
    bool calibrationRrequaried;
public:
    Gyroscope(double s, bool a=true)
    {
        angularVelocity = s;
        calibrationRrequaried = a;
    }
    void calibrate() {
        calibrationRrequaried = false;
    }
    void printStatus() {
        cout << "Скорость: " << angularVelocity << "\u00B0/c" << " | ";
        if (calibrationRrequaried)
            cout << "Калибровка требуется" << endl;
        else
            cout << "Калибровка не требуется" << endl;
    }
};
int main()
{
    system("chcp 1251 > nul");
    Gyroscope g1(120.5);
    g1.printStatus();
    g1.calibrate();
    g1.printStatus();
}
