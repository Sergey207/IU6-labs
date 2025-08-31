#include <climits>
#include <iostream>

using namespace std;

void cin_massive(int (&massive)[30])
{
    for (int &i: massive)
        cin >> i;
}

bool is_int_in_massive(const int n, int (&massive)[30])
{
    for (const int &i: massive)
    {
        if (i == n)
            return true;
    }
    return false;
}

int main()
{
    int a[30], b[30];
    cout << "Please enter 30 numbers for the first sequence:\n";
    cin_massive(a);
    cout << "Please enter 30 numbers for the second sequence:\n";
    cin_massive(b);

    int result = INT_MIN;
    for (const int i: b)
    {
        if (i > result)
        {
            if (!is_int_in_massive(i, a))
                result = i;
        }
    }
    cout << "The largest number in the second sequence that is not in the first: " << result << endl;
    return 0;
}
