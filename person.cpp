/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Person class is a polymorphic class and is the
**                  base class for Student and Instructor classes.
**
**
*********************************************************************/
#include "person.hpp"

void Person::setName(std::string name) {
    this->name = name;
}

void Person::getName() {
    return name;
}

void Person::do_work() {
    std::cout << "Doing person work!\n";
}