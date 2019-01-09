/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Student class instantiates objects of type Student
**                  and are assigned to a pointer that points to its
**                  base class data type. The Student class is a
**                  specialized version of the Person class since it
**                  holds information about students. This class has
**                  two virtual functions that override the behavior
**                  of the Person class functions.
*********************************************************************/
#include "student.hpp"


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
    std::cout << getName() << " did " << generateHoursWorked()
              << " hours of homework.\n\n";
}