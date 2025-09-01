#include <iostream>

#include "ComfortPlate.h"
#include "Plate.h"
using namespace std;

int main() {
    PowerControl pc1{100};
    ComfortPlate cp1{&pc1, 800};

    PowerControl pc2{0};
    ComfortPlate cp2{&pc2, 2000};

    PowerControl pc3{50};
    ComfortPlate cp3{&pc3, 2000};

    PowerControl pc4{75};
    ComfortPlate cp4{&pc4, 2000};

    ComfortPlate *plates[] = {&cp1, &cp2, &cp3, &cp4};
    Plate plate{plates, 4};

    plate.getInfo();

    cout << "Changing power...\n";
    const int result = plate.getComfortPlate(3)->getPowerControl()->setPower(1000);
    cout << (result == 0 ? "Success" : "Fail") << endl;
    plate.getComfortPlate(3)->getInfo();
    return 0;
}
