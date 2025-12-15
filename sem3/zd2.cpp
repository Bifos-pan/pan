#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double altitude(double V, double t, double g)
{
	return V * t - 0.5 * g * t * t;
}
int main()
{
	vector<double>h;
	vector<double>times;
	system("chcp 1251 > nul");
	double v0 = 50;
	double g = 9.81;
	double dt = 1;
	for (double t = 0;; t += dt)
	{
		times.push_back(t);
		h.push_back(altitude(v0, times[t], g));
		if (h[t] < 0) {
			h[t] = 0;
			break;
		}
	}
	cout << "N\tВремя\tВысота" << endl;
	for (int i = 1; i < h.size(); i++)
		cout << i << "\t" << times[i] << "\t" << h[i] << endl;
	if (!h.empty()) {
		vector<double>::iterator maxElement = max_element(h.begin(), h.end());
		int maxIndex = distance(h.begin(), maxElement);

		cout << "\nМаксимальная высота: " << *maxElement << " м" << endl;
		cout << "Время достижения: " << times[maxIndex] << " с" << endl;
		cout << "Индекс в массиве: " << maxIndex << endl;
		}
	else {
		cout << "\nВектор пуст!" << endl;
	}
}
