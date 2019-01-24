/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Student class instantiates objects of type Student
**                  and are assigned to a pointer that points to its
**                  base class data type. The Student class is a
**                  specialized version of the Person class since it
**                  holds information about students. This class has
**                  two virtual functions that override the behavior
**                  of the Person class functions. Student inherits
**                  its functions and variables from Person via Public.
*********************************************************************/
#include "student.hpp"

/*********************************************************************
** Description:    default constructor that sets the GPA data member
*********************************************************************/
Student::Student() : gpa{0.0} {}

/*********************************************************************
** Description:    3-arg constructor that sets the GPA data member as
**                  well as the inherited member variables from its
**                  base class. Uses constructor initialization list.
*********************************************************************/
Student::Student(double gpa, string name, int age)
    : gpa{gpa}, Person{name, age} {
}

/*********************************************************************
** Description:    setter function for GPA data member
*********************************************************************/
void Student::setGPA(double gpa) {
    this->gpa = gpa;
}

/*********************************************************************
** Description:    getter function that gets the GPA data member
*********************************************************************/
double Student::getGPA() {
    return gpa;
}

/*********************************************************************
** Description:     virtual function that overrides the base class
**                  function that displays how many hours a student
**                  studies
*********************************************************************/
void Student::do_work() {
    std::cout << getName() << " did " << generateHoursWorked()
              << " hours of homework.\n\n";
}