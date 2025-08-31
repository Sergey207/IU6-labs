#include "do_while_solution.h"

long do_while_solution(const long k)
{
    long f1=0, f2=1;
    long temp;
    do
    {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    } while (f2 <= k);
    return f2;
}
