﻿
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_fall(double h) {
    return h <= 0.0;
}

int main() {
    vector<double> times1;
    vector<double> heights1;

    vector<double> times2;
    vector<double> heights2;

    times1.push_back(0);
    times1.push_back(1);
    times1.push_back(2);
    times1.push_back(3);
    times1.push_back(4);

    heights1.push_back(0);
    heights1.push_back(20);
    heights1.push_back(35);
    heights1.push_back(10);
    heights1.push_back(-5);

    times2.push_back(0);
    times2.push_back(1);
    times2.push_back(2);
    times2.push_back(3);
    times2.push_back(4);
    times2.push_back(5);

    heights2.push_back(0);
    heights2.push_back(25);
    heights2.push_back(40);
    heights2.push_back(30);
    heights2.push_back(5);
    heights2.push_back(-2);

    double max1 = *max_element(heights1.begin(), heights1.end());
    size_t idx_max1 = distance(heights1.begin(),
        max_element(heights1.begin(), heights1.end()));
    double t_max1 = times1[idx_max1];

    double max2 = *max_element(heights2.begin(), heights2.end());
    size_t idx_max2 = distance(heights2.begin(),
        max_element(heights2.begin(), heights2.end()));
    double t_max2 = times2[idx_max2];

    vector<double>::iterator it1 = find_if(heights1.begin(), heights1.end(), is_fall);
    vector<double>::iterator it2 = find_if(heights2.begin(), heights2.end(), is_fall);

    bool fell1 = (it1 != heights1.end());
    bool fell2 = (it2 != heights2.end());

    double t_fall1 = fell1 ? times1[distance(heights1.begin(), it1)] : -1.0;
    double t_fall2 = fell2 ? times2[distance(heights2.begin(), it2)] : -1.0;

    cout << "Rocket comparison table:" << endl;
    cout << "Rocket 1: max_height = " << max1
        << ", time_of_max = " << t_max1
        << ", time_of_fall = " << (fell1 ? t_fall1 : -1) << endl;

    cout << "Rocket 2: max_height = " << max2
        << ", time_of_max = " << t_max2
        << ", time_of_fall = " << (fell2 ? t_fall2 : -1) << endl;

    if (max1 > max2) {
        cout << "Rocket 1 reached higher altitude" << endl;
    }
    else if (max2 > max1) {
        cout << "Rocket 2 reached higher altitude" << endl;
    }
    else {
        cout << "Both rockets reached the same maximum height" << endl;
    }

    if (!fell1 && !fell2) {
        cout << "Both rockets are still in the air" << endl;
    }
    else if (!fell1) {
        cout << "Rocket 1 stayed in the air longer" << endl;
    }
    else if (!fell2) {
        cout << "Rocket 2 stayed in the air longer" << endl;
    }
    else if (t_fall1 > t_fall2) {
        cout << "Rocket 1 stayed in the air longer" << endl;
    }
    else if (t_fall2 > t_fall1) {
        cout << "Rocket 2 stayed in the air longer" << endl;
    }
    else {
        cout << "Both rockets stayed in the air for the same time" << endl;
    }

    return 0;
}