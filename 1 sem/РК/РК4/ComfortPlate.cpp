#include "ComfortPlate.h"
#include <iostream>

using namespace std;

ComfortPlate::ComfortPlate(PowerControl *powerControl, int maxPower) {
    powerControl_ = powerControl;
    maxPower_ = maxPower > 0 ? maxPower : DEFAULT_MAX_POWER;
}

int ComfortPlate::setMaxPower(int maxPower) {
    if (maxPower > 0) {
        maxPower_ = maxPower;
        return 0;
    }
    return -1;
}

int ComfortPlate::getMaxPower() {
    return maxPower_;
}

int ComfortPlate::getPower() {
    return maxPower_ * powerControl_->getPower() / 100;
}

PowerControl *ComfortPlate::getPowerControl() {
    return powerControl_;
}

void ComfortPlate::getInfo() {
    cout << "Max power: " << getMaxPower() << endl;
    cout << "Power Control: " << powerControl_->getPower() << "%\n";
    cout << "Power: " << getPower() << endl;
}
