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
airplane inrand(airplane& obj,int i){
 for (int i = 0; i < 20; i++)
        cout << "-";
    cout << endl;
    cout << "Самолет " << i + 1 << endl;
    for (int i = 0; i < 20; i++)
        cout << "-";
    cout << endl;
    obj.m = 20000 + rand() % 20000;
    cout << "массa самолета " << obj.m << endl;
    obj.s=50+rand()%25;
    cout << "площадь крыла " << obj.s << endl ;
    obj.T=130000+rand()%40000;

    cout << "тягa двигателя " << obj.T << endl;
    obj.Cl =0.4;
    cout << "коэфициент подъемной силы " << obj.Cl << endl; 
    obj.Cd= 0.035;
    cout << "коэфициент сопротивления " << obj.Cd << endl;
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
double speedup(airplane obj, double ro, double v, int i)
{
    double ay = (up(obj, ro, v) - obj.m * 10) / obj.m;
    double a = (obj.T - resist(obj, ro, v) / obj.m);
    if (ay <= 0 || a <= 0)
    {
        cout << "При заданных параметрах самолет не полетит, поменяйте параметры самолета " << endl;
        in(obj, i);
        return speed(obj, ro, v, i);
    }
    return ay;
}
double time(airplane obj, double ro, double v, double h, int i)
{
    double t = sqrt(2 * h / speedup(obj, ro, v, i));
    return t;
}
void show(airplane obj, double ro, double v, int i)
{
    cout << "Подъемная сила " << up(obj, ro, v) << endl;
    cout << "Сопротивление " << resist(obj, ro, v) << endl;
    cout << "Ускорение " << speed(obj, ro, v, i) << endl;
    cout << "Вертикальное ускорение " << speedup(obj, ro, v, i) << endl;
}
void sort (int n, double* t){
    double f = 0;
    double* num = new double[n];
    for (int i = 0; i < n; i++)
        num[i] = t[i];
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n - 1; i++)
            if (num[i] < num[i + 1])
            {
                f = num[i];
                num[i] = num[i + 1];
                num[i + 1] = f;
            }
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (num[i] != t[j])
            j++;
        cout << "самолет " << j + 1 << " поднимется за " << t[j] << " сек " << endl;
    }
    delete[]num;
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
        inrand(s[i], i);
        show(s[i], ro, v, i);
    }
    double h;
    cout << "Введите высоту которую необходимо набрать ";
    cin >> h;
    double* t = new double[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = time(s[i], ro, v, h, i);  
    }
     sort(n, t);
    delete[]t;
    delete[]s;
    return 0;
}