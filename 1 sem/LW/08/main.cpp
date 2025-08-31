#include <iostream>

#include "Human.h"
#include "Student.h"
using namespace std;

int main() {
    Human me{"Iozhitsa Sergey", 2007};
    me.print_info();
    cout << "Age: " << me.get_age(2024) << endl;

    cout << "--------------------------------" << endl;
    const auto me_student = new Student("Iozhitsa Sergey", 2007,
                                        2024, "BMSTU");
    me_student->print_info();
    cout << "Admission age: " << me_student->get_admission_age() << endl;
    cout << "Age when I end BMSTU: " << me_student->get_age(2030) << endl;

    return 0;
}

