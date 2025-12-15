#include <iostream>
#include<vector>
using namespace std;
struct Points
{
	double x=0, y=0, z=0;
};
int main()
{
	Points p;
	
	system("chcp 1251 > nul");
	vector<vector<double>>trajectory;
		double vx = 30, vy = 20, vz = 40;
		double dt = 1;
		double t_max = 10;
		for (double t = 0; t <= t_max; t += dt)
		{
			p.x += vx * dt;
			p.y += vy * dt;
			p.z += vz * dt;
			trajectory.push_back({t, p.x, p.y, p.z });
		}
		cout << "Время\t" << "x\t" << "y\t" << "z\t" << endl;
		for (int i = 0; i < trajectory.size(); i++)
			cout << trajectory[i][0] << "\t" << trajectory[i][1] << "\t" << trajectory[i][2] << "\t" << trajectory[i][3] << endl;
}
