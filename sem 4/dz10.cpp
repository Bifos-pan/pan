#include <iostream>
#include<vector>
using namespace std;
class DroneFlight
{
private:
	vector<double> x, y;
	double totalDistance;
public:
	DroneFlight(double a = 0, double b = 0, double td=0) {
		totalDistance = td;
	}
	void addPoint(double newX, double newY)
	{
		if(!x.empty() && !y.empty())
		totalDistance+= sqrt(pow(newX - x.back(), 2) + pow(newY - y.back(), 2));
		x.push_back(newX);
		y.push_back(newY);
		
	}
	void printPath() {
		cout << "Точки мартшрута";
		for (int i = 0; i < x.size(); i++) {
			cout << "(" << x[i] << "," << y[i] << ")" << endl;
		}
		cout << "Пройдено: " << totalDistance << "м";
		}
};
int main()
{
	system("chcp 1251 > nul");
	DroneFlight d;
	d.addPoint(0, 0);
	d.addPoint(3, 4);
	d.addPoint(6, 8);
	d.printPath();

}
