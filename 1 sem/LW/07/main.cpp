#include "Cat.h"

#include <iostream>
using namespace std;

int main() {
    Cat cat1{"Murzik", "Black", false};
    cat1.print_info();
    cat1.play();
    cat1.print_info();
    cat1.feed();
    cat1.print_info();

    cout << "------------------------------" << endl;

    Cat cat2{"Funtik", "Gray", true};
    cat2.print_info();
    cat2.feed();
    cat2.print_info();
    cat2.play();
    cat2.print_info();

    return 0;
}

