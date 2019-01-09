/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "student.hpp"
#include <iostream>

Student::Student() : gpa{0.0} { }

Student::Student(double gpa, string name, int age)
    : gpa{gpa}, Person{name, age} {
}

void Student::setGPA(double gpa) {
    this->gpa = gpa;
}

double Student::getGPA() {
    return gpa;
}

void Student::do_work() {
    std::cout << getName() << " did " << generateHoursWorked() << " hours of homework!\n\n";
}