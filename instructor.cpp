/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "instructor.hpp"

Instructor::Instructor() : rating{} { }

Instructor::Instructor(double rating, string name, int age)
    : rating{rating}, Person{name, age} {
}

void Instructor::setRating(double rating) {
    this->rating = rating;
}

double Instructor::getRating() {
    return rating;
}

void Instructor::do_work() {
    std::cout << "Doing instructor work!\n";
}00