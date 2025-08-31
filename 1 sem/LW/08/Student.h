#ifndef STUDENT_H
#define STUDENT_H
#include "Human.h"

#include <iostream>
using namespace std;

class Student : public Human {
public:
    Student(const string &full_name, int year_of_birth,
            int admission_to_university_year,
            const string &university_name);

    void print_info();

        int get_admission_age();

private:
    int admission_to_university_year_;
    string university_name_;
};


#endif //STUDENT_H

