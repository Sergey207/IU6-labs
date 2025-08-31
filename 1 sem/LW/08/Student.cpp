#include "Student.h"

Student::Student(const string &full_name, const int year_of_birth,
                 const int admission_to_university_year,
                 const string &university_name) : Human(full_name, year_of_birth) {
    admission_to_university_year_ = admission_to_university_year;
    university_name_ = university_name;
}

void Student::print_info() {
    Human::print_info();
    cout << "University name: " << university_name_ << endl;
    cout << "Admission to university year: " << admission_to_university_year_ << endl;
}

int Student::get_admission_age() {
    return admission_to_university_year_ - year_of_birth_;
}
