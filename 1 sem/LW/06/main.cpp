#include <cstring>
#include <iostream>

using namespace std;

int main() {
    const int N = 50;
    cout << "Enter string (max 50 symbols, no spaces):\n";
    char str[N];
    cin >> str;

    cout << "Enter the index of the character to exclude [1; " << N << "]: ";
    int index;
    cin >> index;
    if (!(1 <= index && index <= N))
        return -1;
    const char char_to_exclude = str[index - 1];

    char result[N];
    index = 0;
    const size_t length = strlen(str);
    for (int i = 0; i < length; ++i) {
        if (str[i] != char_to_exclude) {
            int count = 0;
            for (int j = 0; j < length && count <= 2; ++j) {
                if (str[i] == str[j])
                    count++;
            }
            if (count <= 2)
                result[index++] = str[i];
        }
    }
    result[index] = '\0';

    cout << "Initial list:\n" << str << endl;
    cout << "Result list:\n" << result << endl;
    return 0;
}
