#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

ld function(const ld x) {
    return log(x);
}

ld integrate(const ld a, const ld b, const ld eps) {
    int n = 1;
    ld previousArea = 0;
    ld currentArea = ((b - a) / n) * function((b - a) / 2);

    while (fabs(currentArea - previousArea) > eps) {
        n *= 2;
        ld sum = 0;
        ld step = (b - a) / n;
        for (int i = 1; i <= n; ++i) {
            sum += function(a + i * step - step / 2);
        }
        previousArea = currentArea;
        currentArea = step * sum;
    }
    return currentArea;
}

int main() {
    ld eps;
    cout << "Enter eps: ";
    cin >> eps;

    ld area = integrate(1, 2, eps);
    cout << "The estimated area is: " << setprecision(16) << area << endl;
    return 0;
}



