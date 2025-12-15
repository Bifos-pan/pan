#include <iostream>
using namespace std;
double Ay(double m, double l)
{
	double 	ay = (l - m * 9.8) / m;
	return ay;
}
double time(double ay, double h)
{
	if (ay < 0 || h < 0)
		cout << "Высота и ускорение должны быть больше 0";
	else
	return sqrt(2 * h / ay);
}
int main()
{
	system("chcp 1251 > nul");
	double m, l, t, ay,h;
	cout << "Введиите массу самолета, подъемную силу ";
	cin >> m >> l;
	ay = Ay(m, l);
	cout << "Введите высоту полета ";
	cin >> h;
	cout << "Чтобы набрать высоту " << h << " при вертикальном ускорении " << ay << " необходимо " << time(ay, h) << " сек";
	return 0;
}