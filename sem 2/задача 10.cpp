#include <iostream>
using namespace std;
struct airplane
{
	double m;
	double s;
	double T;
	double Cd;
	double Cl;

};
airplane in(airplane& obj) {
    cout << endl;
    cout << "Введите массу самолета ";
    cin >> obj.m;
    while (obj.m <= 0)
    {
        cout << "Масса должна быть больше нуля ";
        cin >> obj.m;
    }
    cout << "Введите площадь крыла ";
    cin >> obj.s;
    while (obj.s <= 0)
    {
        cout << "Площадть крыла должна быть больше нуля ";
        cin >> obj.s;
    }
    cout << "Введите коэфициент подъемной силы ";
    cin >> obj.Cl;
    while (obj.Cl <= 0)
    {
        cout << "Коэфициент подъемной силы должен быть больше нуля ";
        cin >> obj.Cl;
    }
    cout << "Введите коэфициент сопротивления ";
    cin >> obj.Cd;
    while (obj.Cd <= 0)
    {
        cout << "Коэфициент сопротивления должен быть больше нуля ";
        cin >> obj.Cd;
    }
    return obj;
}
airplane inT(airplane& obj, double T) {
    obj.T = T;
    return obj;
}
double up(airplane obj, double ro, double v)
{
    double l = 0.5 * ro * pow(v, 2) * obj.s * obj.Cl;
    return l;
}
double speedup(airplane obj, double ro, double v)
{
    double ay = (up(obj, ro, v) - obj.m * 10) / obj.m;
    if (ay <= 0)
    {
        cout << "При заданных параметрах самолет не полетит, поменяйте параметры самолета " << endl;
        in(obj);
        return speedup(obj, ro, v);
    }
    return ay;
}
double time(airplane obj, double ro, double v, double h)
{
    double t = sqrt(2 * h / speedup(obj, ro, v));
    return t;
}
int main()
{
	system("chcp 1251 > nul");
    airplane s;
    double ro, v;
    cout << "Введите параметры полета (скорость и плотность воздуха) ";
    cin >> v >> ro;
	double Tmin, Tmax, dT;
	cout << "Введите минимальную тягу двигателя,максимальную тягу и шаг изменения";
	cin >> Tmin >> Tmax >> dT;
    double h;
    cout << "Введите высоту которую необходимо набрать ";
    cin >> h;
	int n = (Tmax - Tmin) / dT;
	double* T = new double[n];
    double* Time = new double[n];
    double* Ay = new double[n];
    T[0] = Tmin;
    for (int i = 1; i <= n; i++)
        T[i] = T[i - 1] + dT;
    for (int i = 0; i <= n; i++){
        Time[i] = time(s, ro, v, h);
        Ay[i] = speedup(s, ro, v);


	delete[]T;
    delete[]Time;
    delete[]Ay;
}
