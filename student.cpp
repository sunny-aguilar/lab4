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

Student::Student(double gpa) : gpa{gpa} { }

void Student::setGPA(double gpa) {
    this->gpa = gpa;
}

double Student::getGPA() {
    return gpa;
}

void Student::do_work() {
    std::cout << "Doing student work!\n";
}