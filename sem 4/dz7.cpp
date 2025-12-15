#include <iostream>
using namespace std;
class FlightComputer {
private:
	double altitude;
	double velocity;
	double fuel;
	double thrust;
public:
	FlightComputer(double a, double v, double f, double t)
	{
		altitude = a;
		velocity = v;
		fuel = f;
		thrust = t;
	}
	void simulateStep(double dt)
	{
		velocity += (thrust / 1000.0 - 9.8) * dt;
		altitude += velocity * dt;
		fuel -= dt * 2;
	}
	void printStatus(double t)
	{
		cout << "Время: " << t << endl;
		cout << "Высота: " << altitude << endl;
		cout << "Скорость: " << velocity << endl;
		cout << "Запас топлива: " << fuel << endl;
		cout << "Тяга: " << thrust << endl;
		for (int i = 0; i < 25; i++)
			cout << "-";
		cout << endl;
	}

};
int main()
{
	double t = 0;
	system("chcp 1251 > nul");
	FlightComputer fc(0, 0, 100, 12000);
	for (int i = 0; i < 5; i++) {
		t += 0.5;
		fc.simulateStep(0.5);
		fc.printStatus(t);
	}
}
