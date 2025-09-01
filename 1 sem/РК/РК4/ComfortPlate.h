#ifndef COMFORTPLATE_H
#define COMFORTPLATE_H
#include "PowerControl.h"


class ComfortPlate {
public:
    ComfortPlate(PowerControl *powerControl, int maxPower);

    int setMaxPower(int maxPower);

    int getMaxPower();

    PowerControl* getPowerControl();

    int getPower();

    void getInfo();
private:
    const int DEFAULT_MAX_POWER = 1000;
    PowerControl *powerControl_;
    int maxPower_;
};


#endif //COMFORTPLATE_H
