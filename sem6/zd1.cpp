#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TrajectoryLogger
{
	ofstream fout;
private:
	vector<double>x;
	vector<double>y;
	vector<double>z;
	vector<double>speed;
	vector<double>time;
public:
	TrajectoryLogger(const string& filename) {
		fout.open(filename, ios::out);
		if (!fout.is_open())
			throw runtime_error("Eror");
		fout << "x, y, z, speed, time\n";
	}
	void addPoint(double X,double Y, double Z, double Speed, double Time)
	{
		x.push_back(X);
		y.push_back(Y);
		z.push_back(Z);
		speed.push_back(Speed);
		time.push_back(Time);
	}
	double calculateTotalDistance()
	{
		double dist = 0;
		int count;
		for (int i=0;i<x.size();i++)
			dist += sqrt(pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2));
		return dist;
	}
	void printStatistics()
	{
		for (int i=0;i<x.size();i++)
		fout << x[i] << ", " << y[i] << ", " << z[i] << ", " << speed[i] << ", " << time[i] << "\n";
	}
	~TrajectoryLogger() {
		fout.close();
	}
};
int main()
{
	TrajectoryLogger log("log.csv");
	log.addPoint(10.5, 20.3, 100.0, 25, 0);
	log.addPoint(15.2, 25.1, 105,27.5, 1.5);
	log.addPoint(20.8, 30.7, 110, 30, 3);
	log.printStatistics();
	
}
