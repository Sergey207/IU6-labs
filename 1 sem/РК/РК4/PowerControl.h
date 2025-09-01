#ifndef POWERCONTROL_H
#define POWERCONTROL_H


class PowerControl {
public:
    PowerControl();

    PowerControl(int power);

    int setPower(int power);

    int getPower();

private:
    const int DEFAULT_POWER = 0;
    int power_;
};


#endif //POWERCONTROL_H
