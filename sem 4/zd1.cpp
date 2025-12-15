#include <iostream>
using namespace std;
class Sensor
{
private:
	double signalStregh;
	bool isActive;
public:
	Sensor(double strengh) {
		signalStregh = strengh;
		isActive = 1;
	}
	void activate() {
		isActive = 1;
	}
	void deactivate() {
		isActive = 0;
	}
	void setSignalStrength(double s)
	{
		signalStregh = s;
	}
	double getSingalStrength() {
		return signalStregh;
	}
	void printStatus()
	{
		if (isActive)
			cout << "Состояние датчика: Датчик включен" << endl;
		else
			cout << "Состояние датчика: Датчик выключен" << endl;
		cout << "Сила сигнала: " << signalStregh << endl;
	}
};
int main()
{
	system("chcp 1251 > nul");
	Sensor obj(50);
	obj.printStatus();
	obj.deactivate();
	obj.printStatus();
	obj.activate();
	obj.setSignalStrength(1000);
	obj.printStatus();
	double b = obj.getSingalStrength();
	cout << b << endl;
}

