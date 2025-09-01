#include "Plate.h"
#include <iostream>

using namespace std;

Plate::Plate(ComfortPlate **comfortPlates, const int n) {
    if (1 <= n && n <= 4) {
        N = n;
        for (int i = 0; i < N; ++i) {
            comfortPlates_[i] = comfortPlates[i];
        }
    }
}

ComfortPlate * Plate::getComfortPlate(int n) {
    if (0 <= n && n <= N) {
        return comfortPlates_[n];
    }
    return nullptr;
}

void Plate::getInfo() {
    for (int i = 0; i < N; ++i) {
        cout << "Comfort Plate " << i + 1 << ":\n";
        comfortPlates_[i]->getInfo();
        cout << "--------------------------------" << endl;
    }
}

