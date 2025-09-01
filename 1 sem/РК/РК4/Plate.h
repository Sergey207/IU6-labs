#ifndef PLATE_H
#define PLATE_H
#include "ComfortPlate.h"


class Plate {
public:
    Plate(ComfortPlate **comfortPlates, int n);

    ComfortPlate *getComfortPlate(int n);

    void getInfo();
private:
    int N = 0;
    ComfortPlate *comfortPlates_[4];
};


#endif //PLATE_H
