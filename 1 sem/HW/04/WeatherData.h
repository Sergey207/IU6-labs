#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <string>

using namespace std;

class WeatherData {
public:

    WeatherData(const string& date, int temperature, int humidity);

    void printData();

    string getDate();

    int getTemperature();

    int getHumidity();

private:
    string date_;
    int temperature_;
    int humidity_;
};


#endif //WEATHERDATA_H


