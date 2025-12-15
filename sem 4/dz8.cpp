#include <iostream>
using namespace std;
class NavigationSystem
{
private:
	double X, Y;
	double velocityX, velocityY;
	bool gpsAvaiable;
public:
	NavigationSystem(double x, double y, double vx, double vy, bool gps)
	{
		X = x;
		Y = y;
		velocityX = vx;
		velocityY = vy;
		gpsAvaiable = gps;
	}
	void integratePosition(double dt)
	{
		X += velocityX * dt;
		Y += velocityY * dt;
	}
	void correctGPS(double realX, double realY)
	{
		if (gpsAvaiable) {
			X = (X + realX) / 2;
			Y = (Y + realY) / 2;
		}
	}
	void printPosition()
	{
		cout << "Скорректированные координаты: (" << X << "," << Y << ")";
	}
};
int main()
{
	system("chcp 1251 > nul");
	NavigationSystem nav(0, 0, 100, 50, true);
	nav.integratePosition(1);
	nav.correctGPS(110, 60);
	nav.printPosition();
}
