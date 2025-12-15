#include <iostream>
#include<vector>
using namespace std;
double vel(double v0, double t,double g)
{
	return v0 - g * t;
}
int main()
{
	int count=0;
	system("chcp 1251 > nul");
	double v0=60, g=9.81, dt=2, t_max=100;
	vector<double>times, velocities;
	for (double t = 0; t <= t_max; t += dt)
	{
		times.push_back(t);
		velocities.push_back(vel(v0, t, g));
		count++;
		if (velocities[velocities.size()-1] < -100)
			break;
	}
	cout << "N\t" << "Время\t" << "Скорость" << endl;
	for (int i = 0; i < count; i++)
		cout << i << "\t" << times[i] << "c\t" << velocities[i]<< "км/ч" << endl;
}
