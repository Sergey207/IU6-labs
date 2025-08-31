#include "task_2.h"

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void task_2() {
    long double x;
    cout << "Enter x: ";
    cin >> x;

    long double y1 = (exp(x) - exp(-x)) / 2;
    long double y2 = (exp(x) + exp(-x)) / 2;
    long double y = pow(y2, 2) - pow(y1, 2);

    cout << setprecision(16);
    cout << "x: " << x << endl;
    cout << "y1 (sh(x)) = " << setw(20) << y1 << endl;
    cout << "y2 (ch(x)) = " << setw(20) << y2 << endl;
    cout << "y (y2^2 - y1^2) = " << setw(20) << y << endl;
    cout << "Абсолютная погрешность: " << setw(20) << fabs(1 - y) << endl;
    cout << "Относительная погрешность: " << setw(20) << fabs(1 - y) / 1 << endl;
}
