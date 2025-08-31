#include <iostream>

#include "do_while_solution.h"
#include "for_solution.h"
#include "while_solution.h"

using namespace std;

int main()
{
    long k;
    cout << "Type k: ";
    cin >> k;

    cout << "Result: " << while_solution(k) << endl;
    // cout << "Result: " << do_while_solution(k) << endl;
    // cout << "Result: " << for_solution(k) << endl;
    return 0;
}
