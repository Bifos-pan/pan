#include <iostream>
using namespace std;
class RocketStage {
private:
    double thrust;
    double burnTime;
    double mass;
public:
    RocketStage(double T, double bt, double m)
    {
        thrust = T;
        burnTime = bt;
        mass = m;
    }
    double getDelta() {
        return (thrust*burnTime)/mass;
    }
    void printInfo() {
        cout << "Тяга двигателя " << thrust << " " << "время работы " << burnTime << " " << "масса ступени " << mass << endl;
    }
};
    
int main()
{
    system("chcp 1251 > nul");
    RocketStage s1(5000, 10, 1000);
    RocketStage s2(7000, 8, 900);
    RocketStage s3(9000, 6, 800);
    double totalV = s1.getDelta() + s2.getDelta() + s3.getDelta();
    cout << "Итоговая скорость ракеты: " << totalV << "м/c";
}
