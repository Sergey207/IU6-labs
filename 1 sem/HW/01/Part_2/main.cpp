#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    cout << "This program solves ax^2+bx+c=0\n";
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "x = any (infinitely many solutions)\n";
            } else {
                cout << "No solution exists\n";
            }
        } else {
            cout << "x = " << -c / b << endl;
        }
    } else {
        const double d = pow(b, 2) - 4 * a * c;
        if (d < 0) {
            cout << "No solution exists\n";
        } else if (d == 0) {
            cout << "x = " << -b / (2 * a) << endl;
        } else {
            cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
        }
    }
    return 0;
}





