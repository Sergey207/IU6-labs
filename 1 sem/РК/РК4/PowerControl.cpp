#include "PowerControl.h"

PowerControl::PowerControl() {
    power_ = DEFAULT_POWER;
}

PowerControl::PowerControl(const int power) {
    power_ = (0 <= power && power <= 100) ? power : DEFAULT_POWER;
}

int PowerControl::setPower(const int power) {
    if (0 <= power && power <= 100) {
        power_ = power;
        return 0;
    }
    return -1;
}

int PowerControl::getPower() {
    return power_;
}
