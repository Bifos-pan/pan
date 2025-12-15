#include <iostream>
using namespace std;
class Trajectory
{
private:
	double startX, startY;
	double angle;
public:
	Trajectory() {
		startX = 0;
		startY = 0;
		angle = 0;
	}
	Trajectory(double x, double y, double ang) {
		startX = x;
		startY = y;
		angle = ang;
	}
	void printTrajectory() {
		cout << "Старт (" << startX << "," << startY<< ")"  << "," << "Угол: " << angle << "\u00B0" << endl;
	}
};
int main()
{
	system ("chcp 1251 > nul");
	Trajectory t1;
	t1.printTrajectory();
	Trajectory t2(100, 200, 45);
	t2.printTrajectory();
}
