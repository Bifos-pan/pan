#include <iostream>
#include<cmath>
using namespace std;
double resist(double ro, double s, double v, double cd)
{
	double l;
	l = 0.5 * ro * pow(v, 2) * s * cd;
	return l;
}
int main()
{
	system("chcp 1251 > nul");
	double ro, s, v, cd;
	cout << "Введите параметры для рассчета полета" << endl;
	cout << "Площадь крыла самолета ";
	cin >> s;
	cout << "Скорость полета ";
	cin >> v;
	cout << "Плотность воздуха ";
	cin >> ro;
	cout << "Коэфициент сопротивления ";
	cin >> cd;
	cout << "Aэродинамическое сопротивление равно " << resist(ro,s,v,cd);
	return 0;
}

