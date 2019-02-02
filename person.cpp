/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Person class is the base class for the Student
**                  class and Instructor class. Person class has
**                  various virtual functions that allow for
**                  polymorphic behavior. Person class does not have
**                  any pure virtual functions so it is not an abstract
**                  class.
*********************************************************************/
#include "person.hpp"

/*********************************************************************
** Description:    default constructor that sets the data members
*********************************************************************/
Person::Person() : name{}, age{0} { }

/*********************************************************************
** Description:     2-arg constructor that sets the data member. Uses
**                  constructor initialization list.
*********************************************************************/
Person::Person(string name, int age) : name{name}, age{age} { }

/*********************************************************************
** Description:    setter function for name data member
*********************************************************************/
void Person::setName(string name) {
    this->name = name;
}

/*********************************************************************
** Description:    getter function for name data member
*********************************************************************/
string Person::getName() {
    return name;
}

/*********************************************************************
** Description:    setter function for name data member
*********************************************************************/
void Person::setAge(int age) {
    this->age = age;
}

/*********************************************************************
** Description:    getter function for name data member
*********************************************************************/
int Person::getAge() {
    return age;
}

/*********************************************************************
** Description:     generates a random integer from 1 - 8 that
**                  represents hours worked and returns it
*********************************************************************/
int Person::generateHoursWorked() {
    unsigned seed;
    int hours;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    hours = rand() % 8 + 1;
    return hours;
}

/*********************************************************************
** Description:     virtual function that changes its behavior
**                  depending on which object it is called from
*********************************************************************/
void Person::do_work() {
    std::cout << "Doing person work!\n";
}

/*********************************************************************
** Description:     virtual function that changes its behavior
**                  depending on which object it is called from
*********************************************************************/
double Person::getGPA() {
    std::cout << "Error! Person does not have a GPA\n";
    return 0;
}

/*********************************************************************
** Description:     virtual function that changes its behavior
**                  depending on which object it is called from
*********************************************************************/
double Person::getRating() {
    std::cout << "Error! Person doe snot have a Rating\n";
    return 0;
}