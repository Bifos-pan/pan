#include <iostream>
using namespace std;
class Autopilot {
private:
    double courseAngle;
    double altitude;
public:
    Autopilot(double course = 0, double alti = 0) {
        courseAngle = course;
        altitude = alti;
    }
    void changeCourse(double delta) {
        courseAngle += delta;
    }
    void changeAltitude(double delta) {
        altitude += delta;
    }
    void printStatus() {
        cout << "Курс: " << courseAngle << "\u00B0,высота: " << altitude << "м" << endl;
    }
};
int main()
{
    system("chcp 1251 > nul");
    Autopilot a1(90, 1000);
    a1.printStatus();
    a1.changeCourse(10);
    a1.changeAltitude(500);
    a1.printStatus();
}
