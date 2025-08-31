#ifndef CAT_H
#define CAT_H
#include <string>

using namespace std;

class Cat {
public:
    Cat(const string& name, const string& color, bool hungry = true);
    void print_info();
    void feed();
    void play();

private:
    string name_, color_;
    bool hungry_;
};



#endif //CAT_H

