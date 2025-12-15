#include <iostream>
#include <iomanip>
using namespace std;
double up(double v, double ro,int n,double cl)
{
	double L;
	L = 0.5 * ro * pow(v, 2) * cl;
	return L;
}
//void in(double* mas, int n)
//{
//	for (int i = 0; i < n; i++)
//		cin >> mas[i];
//}
void out(double* v, double* ro, int n, double cl)
{
	for (int i = 0; i < n; i++)
		cout << setw(7) << v[i];
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl << ro[i];
		for (int j = 0; j < n; j++)
			cout << setw(7) << up(v[j], ro[i], n, cl);

	}
}
	void in(double* mas,int n)
	{
		for (int i = 0; i < n; i++)
			mas[i] = rand() % 10;
	}

int main()
{
	system("chcp 1251 > nul");
	int n;
	double cl;
	cout << "Введите колчиство этапов полета";
	cin >> n;
	cout << "Введите коэфициеент сопротивления ";
	cin >> cl;
	double* v = new double[n];
	double* ro = new double[n];
	in(ro, n);
	in(v, n);
	out(ro, v, n, cl);
}
