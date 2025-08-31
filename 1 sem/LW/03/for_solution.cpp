#include "for_solution.h"

long for_solution(const long k)
{
    long f1=0, f2=1;
    for (long temp; f2 <= k; f2=temp)
    {
        temp = f1+f2;
        f1 = f2;
    }
    return f2;
}
