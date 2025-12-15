#include <iostream>
using namespace std;
int main()
{
	system ("chcp 1251 > nul");
	double m, l, d, t, a, ay;
	cout << "Введиите массу самолета, подъемную силу, споротивление и тягу двигателя ";
	cin >> m >> l >> d >> t;
	a = (t - d) / m;
	cout << "Ускорение по направлению движения а=" << a;
	ay = (l - m * 9.8) / m;
	cout << "\nВертикальное ускорение Ay=" << ay;
	return 0;
}