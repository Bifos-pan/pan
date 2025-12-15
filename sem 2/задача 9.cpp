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
double up(airplane obj, double ro, double v)
{
    double l = 0.5 * ro * pow(v, 2) * obj.s * obj.Cl;
    return l;
}
double resist(airplane obj, double ro, double v)
{
    double l = 0.5 * ro * pow(v, 2) * obj.s * obj.Cd;
    return l;
}
airplane in(airplane& obj, int i) {
    for (int i = 0; i < 20; i++)
        cout << "-";
    cout << endl;
    cout << "Самолет " << i + 1 << endl;
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
double speed(airplane obj, double ro, double v, int i)
{
    double a = (obj.T - resist(obj, ro, v)) / obj.m;
    double ay = (up(obj, ro, v) - obj.m * 10) / obj.m;
    if (a <= 0 || ay <= 0)
    {
        cout << "При заданных параметрах самолет не полетит, поменяйте параметры самолета" << endl;
        in(obj, i);
        return speed(obj, ro, v, i);
    }
    return a;
}
void show(airplane obj, double ro, double v, int i)
{
    cout << "Подъемная сила " << up(obj, ro, v) << endl;
    cout << "Сопротивление " << resist(obj, ro, v) << endl;
    cout << "Ускорение " << speed(obj, ro, v, i) << endl;
}
int main()
{
    system("chcp 1251 > nul");
    double ro, v;
    int n;
    cout << "Введите количество самолетов ";
    cin >> n;
    airplane* s = new airplane[n];
    cout << "Введите параметры полета (скорость и плотность воздуха) ";
    cin >> v >> ro;
    while (v <= 0 || ro <= 0) {
        cout << "Скорость и плотность должны быть больше нуля ";
        cin >> v >> ro;
    }
    for (int i = 0; i < n; i++) {
        in(s[i], i);
        show(s[i], ro, v, i);
    }
    double max = speed(s[0], ro, v, 0);
        int maxind=0;
    for (int i = 0; i < n; i++)
        if (speed(s[i], ro, v, i) > max) {
            max = speed(s[i], ro, v, i);
            maxind = i;
        }
    cout << endl << "Наибольшее ускорение имеет самолет " << maxind+1;
    delete[]s;
    return 0;
}