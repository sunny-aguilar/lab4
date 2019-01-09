/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Person class is a polymorphic class and is the
**                  base class for Student and Instructor classes.
**
**
*********************************************************************/
#include "person.hpp"

Person::Person() : name{}, age{0} { }

Person::Person(string name, int age) : name{name}, age{age} { }

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}

void Person::setAge(int age) {
    this->age = age;
}

int Person::getAge() {
    return age;
}

int Person::generateHoursWorked() {
    unsigned seed;
    int hours;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    hours = rand() % 8 + 1;
    return hours;
}

void Person::do_work() {
    std::cout << "Doing person work!\n";
}

double Person::getGPA() {
    std::cout << "Error! Person does not have a GPA\n";
    return 0;
}

double Person::getRating() {
    std::cout << "Error! Person doe snot have a Rating\n";
    return 0;
}