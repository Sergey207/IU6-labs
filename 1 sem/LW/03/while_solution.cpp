#include "while_solution.h"

long while_solution(const long k)
{

    long f1=0, f2=1;
    long temp;
    while (f2 <= k)
    {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f2;
}
