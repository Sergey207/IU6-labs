#include "Human.h"

#include <iostream>
using namespace std;

Human::Human(const string& full_name, const int year_of_birth) {
    full_name_ = full_name;
    year_of_birth_ = year_of_birth;
}

void Human::print_info() {
    cout << "Human: " << full_name_ << endl;
    cout << "Year_of_birth: " << year_of_birth_ << endl;
}

int Human::get_age(const int year) {
    return year - year_of_birth_;
}
