#include "WeatherDiary.h"

WeatherDiary::WeatherDiary() {

}

WeatherDiary::WeatherDiary(WeatherData weatherObservations[], int N) {
    for (int i = 0; i < N; ++i) {
        data_.push_back(weatherObservations[i]);
    }
}

void WeatherDiary::addData(const WeatherData &weather_data) {
    data_.push_back(weather_data);
}

void WeatherDiary::printDiary() {
    for (auto &obs: data_) {
        obs.printData();
    }
}

int WeatherDiary::getNumOfObservations() {
    return data_.size();
}

double WeatherDiary::getAvgTemp() {
    unsigned long sum = 0;
    for (auto &obs: data_) {
        sum += obs.getTemperature();
    }
    return sum / getNumOfObservations();
}

double WeatherDiary::getAvgHum() {
    unsigned long sum = 0;
    for (auto &obs: data_) {
        sum += obs.getHumidity();
    }
    return sum / getNumOfObservations();
}

int WeatherDiary::getMaxTemp() {
    int res = 0;
    for (auto &obs: data_) {
        res = max(res, obs.getTemperature());
    }
    return res;
}

int WeatherDiary::getMaxHum() {
    int res = 0;
    for (auto &obs: data_) {
        res = max(res, obs.getHumidity());
    }
    return res;
}
