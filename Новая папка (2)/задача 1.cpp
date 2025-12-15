#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	double l, ro, s, v, cl;
	cout << "Введите параметры для рассчета полета" << endl;
	cout << "Площадь крыла самолета ";
	cin >> s;
	cout << "Скорость полета ";
	cin >> v;
	cout << "Плотность воздуха ";
	cin >> ro;
	cout << "Коэфициент подъемной силы ";
	cin >> cl;
	l = 0.5 * ro * pow(v, 2) * s * cl;
	cout << "Подъемная сила равна " << l;
	return 0;
}
