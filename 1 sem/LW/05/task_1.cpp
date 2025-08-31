#include "task_1.h"

#include <iostream>

using namespace std;

void task_1() {
    cout << "Enter matrix 6x6:\n";
    int matrix[6][6];
    for (int i = 0; i < 36; ++i)
        cin >> matrix[i / 6][i % 6];

    cout << "Triangle:\n";
    int cnt = 0;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << matrix[cnt / 6][cnt % 6] << " ";
            cnt++;
        }
        cout << endl;
    }
}

