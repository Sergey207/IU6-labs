#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    cout << "Type x and y: ";
    cin >> x >> y; // Ввод данных

    if (pow(x + 1, 2) + pow(y, 2) <= 1) // Находится ли точка в круге
    {
        if (x >= -1 && y >= 0) // Находится ли точка в I четверти
        {
            cout << "Dot in the area!\n";
        }
        else
        {
            cout << "Dot not in the area!\n";
        }
    }
    else
    {
        cout << "Dot not in the area!\n";
    }

    return 0;
}
