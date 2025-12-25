
﻿#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<double> h;
    h.push_back(10.0);
    h.push_back(12.5);
    h.push_back(9.0);
    h.push_back(15.0);
    h.push_back(14.0);
    h.push_back(13.5);
    h.push_back(16.0);

    size_t n = h.size();
    vector<double> smoothed(n);

    if (n == 0) {
        cout << "Vector is empty" << endl;
        return 0;
    }

    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];

    for (size_t i = 1; i + 1 < n; i++) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    cout << fixed << setprecision(2);
    cout << "Original\tSmoothed" << endl;

    for (size_t i = 0; i < n; i++) {
        cout << h[i] << "\t\t" << smoothed[i] << endl;
    }

    return 0;
}
