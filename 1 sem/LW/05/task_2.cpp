#include "task_2.h"
#include <iostream>

using namespace std;

void task_2() {
    // input
    cout << "Enter n: ";
    int n;
    cin >> n;

    int matrix[n][n];
    cout << "Enter matrix:\n";
    for (int i = 0; i < n * n; ++i)
        cin >> matrix[i / n][i % n];

    // finding max element of the lower triangular matrix
    int mx = matrix[n - 1][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            mx = max(mx, matrix[i][j]);
        }
    }

    // finding sum
    bool wasElement = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (matrix[i][j] > mx) {
                sum += matrix[i][j];
                wasElement = true;
            }
        }
    }

    // output
    cout << "Matrix:" << endl;
    for (const auto &line: matrix) {
        for (const auto &elem: line) {
            cout << elem << "\t";
        }
        cout << endl;
    }
    if (wasElement)
        cout << "Sum of elements: " << sum << endl;
    else
        cout << "There aren't any elements!" << endl;
}
