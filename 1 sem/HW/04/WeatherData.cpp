#include "WeatherData.h"

#include <iostream>
using namespace std;

WeatherData::WeatherData(const string& date, const int temperature, const int humidity) {
    date_ = date;
    temperature_ = temperature;
    humidity_ = humidity;
}

void WeatherData::printData() {
    cout << "Weather date " << date_ << endl;
    cout << "Temperature C: " << temperature_ << endl;
    cout << "Humidity: " << humidity_ << endl;
}

string WeatherData::getDate() {
    return date_;
}

int WeatherData::getTemperature() {
    return temperature_;
}

int WeatherData::getHumidity() {
    return humidity_;
}
