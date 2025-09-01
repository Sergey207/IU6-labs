#include <iostream>
using namespace std;

int main()
{
    // input
    int n, m;
    cout << "Enter n, m: ";
    cin >> n >> m;
    double matrix[n][m];
    cout << "Enter matrix n x m:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // output
    cout << "Matrix before changes:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // finding max element
    int max1 = 0, max2 = 0;
    for (int i = 1; i < m; ++i) {
        if (matrix[i][0] > matrix[max1][0])
            max1 = i;
        if (matrix[i][m - 1] > matrix[max2][m - 1])
            max2 = i;
    }

    // swaping
    const double temp = matrix[max1][0];
    matrix[max1][0] = matrix[max2][m - 1];
    matrix[max2][m - 1] = temp;

    // output changing matrix
    cout << "Matrix after changing:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
