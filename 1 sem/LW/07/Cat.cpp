#include "Cat.h"

#include <iostream>
using namespace std;

Cat::Cat(const string& name, const string& color, const bool hungry) {
    name_ = name;
    color_ = color;
    hungry_ = hungry;
}

void Cat::print_info() {
    cout << "Cat " << name_ << ", " << color_ << ", " << (hungry_? "hungry." : "well-fed.") << endl;
}

void Cat::feed() {
    hungry_ = false;
}

void Cat::play() {
    hungry_ = true;
}


