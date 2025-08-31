#include <cmath>

#include "countP.h"

double countP(double x, double (*f1)(double), double (*f2)(double), double (*f3)(double)) {
    return f1(x) * pow(x, 2) + f2(x) * x + f3(x);
}