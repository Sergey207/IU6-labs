#include <iostream>
#include <cmath>

#include "countP.h"

using namespace std;

double f1_1(double x) {
    return sin(x) * x;
}

double f2_1(double x) {
    return 0.64 * cos(x);
}

double f3_1(double x) {
    return pow(x, 3) - 5;
}

double f1_2(double x) {
    return log(x) * x;
}

double f2_2(double x) {
    return cos(x) * pow(x, 2);
}

double f3_2(double x) {
    return pow(x, 4) + 4;
}



int main() {
    const double x1 = -3.5, x2 = 3;
    cout << "x1: " << x1 << ". Result: " << countP(x1, f1_1, f2_1, f3_1) << endl;
    cout << "x2: " << x2 << ". Result: " << countP(x2, f1_2, f2_2, f3_2) << endl;
    return 0;
}
