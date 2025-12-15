#include <iostream>
using namespace std;
class AutonomousControl
{
private:
	double altitude;
	double thrust;
	double targetAltitude;
public:
	AutonomousControl(double a, double t, double tA)
	{
		altitude = a;
		thrust = t;
		targetAltitude = tA;
	}
	void updateControl()
	{
		if (altitude < targetAltitude)
			thrust += 100;
		if (altitude > targetAltitude)
			thrust -= 100;
	}
	void simulateStep(double dt)
	{
		altitude += thrust / 500 * dt;
	}
	void printStatus() {
		cout << "Высота: " << altitude << endl;
		cout << "Тяга: " << thrust << endl;
		cout << "Целевая высота: " << targetAltitude << endl;

	}
};
int main()
{
	system("chcp 1251 > nul");
	AutonomousControl ac(0, 2000, 5000);
	for (int i = 0; i < 5; i++) {
		ac.updateControl();
		ac.simulateStep(1.0);
		ac.printStatus();
	}
}
