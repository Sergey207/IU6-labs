#include <iostream>

using namespace std;

int main() {
    // Вариант 21
    cout << "This program counts 2/1 * 2/3 * 4/3 * ... n times\n";
    cout << "Type n: ";
    int n; cin >> n;
    long double result = 1;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // i - чётное
            result *= i / (i + 1.0);
        } else { // i - нечетное
            result *= (i + 1.0) / i;
        }
    }
    cout << "Result: " << result << endl;
    return 0;
}

