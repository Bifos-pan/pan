#include <iostream>
using namespace std;
class Engine {
private:
	double thrust;
	double fuelFlow;
public:
	Engine(double T, double F)
	{
		thrust = T;
		fuelFlow = F;
	}
	double getSpecificlmpulse()
	{
		return thrust/(fuelFlow*9.81);
	}
	void printinfo()
	{
		cout << "Тяга: " << thrust << " | " << "Расход: " << fuelFlow << " | " << "Удельный импульс: " << getSpecificlmpulse() << "c";
	}
};
int main()
{
	system("chcp 1251 > nul");
	Engine e1(5000, 2.5);
	e1.printinfo();
}
