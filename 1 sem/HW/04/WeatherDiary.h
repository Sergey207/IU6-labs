#ifndef WEATHERDIARY_H
#define WEATHERDIARY_H
#include <vector>

#include "WeatherData.h"

using namespace std;

class WeatherDiary {
public:
    WeatherDiary();
    WeatherDiary(WeatherData weatherObservations[], int N);

    void addData(const WeatherData& weather_data);

    void printDiary();

    int getNumOfObservations();

    double getAvgTemp();

    double getAvgHum();

    int getMaxTemp();

    int getMaxHum();

private:
    vector<WeatherData> data_;
};
#endif //WEATHERDIARY_H


