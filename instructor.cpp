/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Instructor class instantiates objects of type
**                  Instructor and are assigned to a pointer that
**                  points to its base class data type. The Instructor
**                  class is a specialized version of the Person
**                  class and holds information specific to
**                  OSU instructors. This information is accessed via
**                  its virtual functions that override the behavior
**                  of its base class.
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
    std::cout << getName() << " graded papers for "
              << generateHoursWorked() << " hours.\n\n";
}