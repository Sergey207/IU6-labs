#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human {
public:
    Human(const string &full_name, int year_of_birth);
    void print_info();
    int get_age(int year);

protected:
    string full_name_;
    int year_of_birth_;
};


#endif //HUMAN_H


