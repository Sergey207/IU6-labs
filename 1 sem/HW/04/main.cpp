#include <iostream>

#include "WeatherData.h"
#include "WeatherDiary.h"
using namespace std;

int main() {
    cout << "Enter N days: ";
    int N;
    cin >> N;
    if (N <= 0) {
        cout << "N must be > 1" << endl;
        return -1;
    }

    WeatherDiary wd;
    string date;
    int temperature, huminity;
    for (int i = 0; i < N; ++i) {
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter temperature: ";
        cin >> temperature;
        cout << "Enter humidity: ";
        cin >> huminity;
        wd.addData(WeatherData(date, temperature, huminity));
    }

    cout << "Diary: " << endl;
    wd.printDiary();

    cout << "Average temperature: " << wd.getAvgTemp() << endl;
    cout << "Max temperature: " << wd.getMaxTemp() << endl;
    cout << "Average humidity: " << wd.getAvgHum() << endl;
    cout << "Max humidity: " << wd.getMaxHum() << endl;
    return 0;
}

