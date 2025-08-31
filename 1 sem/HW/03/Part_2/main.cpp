#include <iostream>
using namespace std;

int main() {
    char input_file[128], output_file[128];
    cout << "Enter input filename: ";
    cin >> input_file;
    cout << "Enter output filename: ";
    cin >> output_file;

    FILE *f1 = fopen(input_file, "r");
    if (f1 == nullptr) {
        cout << "File not found!\n";
        return -1;
    }
    FILE *f2 = fopen(output_file, "w");
    char line[128];
    bool isEven = false;
    while (fgets(line, 128, f1)) {
        if (isEven)
            fputs(line, f2);
        isEven = !isEven;
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
