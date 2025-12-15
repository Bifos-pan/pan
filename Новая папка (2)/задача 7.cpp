#include <iostream>
using namespace std;
struct plane
{
	double m;
	double s;
	double T;
	double Cd;
	double Cl;
};
plane in(plane& obj) {
    for (int i = 0; i < 20; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < 20; i++)
        cout << "-";
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
    cout << "Введите тягу двигателя ";
    cin >> obj.T;
    while (obj.T <= 0)
    {
        cout << "Тяга двигателя должна быть больше нуля ";
        cin >> obj.T;
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
double up(plane obj, double ro, double v)
{
    double l = 0.5 * ro * pow(v, 2) * obj.s * obj.Cl;
    return l;
}
double speedup(plane obj, double ro, double v)
{
    double ay = (up(obj, ro, v) - obj.m * 10) / obj.m;
    return ay;
}
void mode(plane obj, double ro, double v)
{
    double ay = speedup(obj, ro, v);
    if (ay > 0)
    {
        cout << "\nРежим набора высоты ";
    }
    else if (ay == 0)
        cout << "\n Режим горизонтального полета";
    else if (ay < 0)
        cout << "\n Режим снижения ";
}
int main()
{
    system("chcp 1251 > nul");
    double ro, v;
    cout << "Введите параметры полета(Плотность воздуха и скорость ";
    cin >> ro >> v;
    plane s1;
    in(s1);
    cout << "Вертикальное ускорение " << speedup(s1, ro, v);
    mode(s1,ro,v);
    return 0;
}
