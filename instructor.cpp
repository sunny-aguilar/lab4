/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
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

/*********************************************************************
** Description:    default constructor that sets the GPA data member
*********************************************************************/
Instructor::Instructor() : rating{0.0} {}

/*********************************************************************
** Description:     3-arg constructor that sets the rating data member
**                  as well as the inherited member variables from its
**                  base class. Uses constructor initialization list.
*********************************************************************/
Instructor::Instructor(double rating, string name, int age)
    : rating{rating}, Person{name, age} {
}

/*********************************************************************
** Description:    setter function for rating data member
*********************************************************************/
void Instructor::setRating(double rating) {
    this->rating = rating;
}

/*********************************************************************
** Description:    getter function that gets the rating data member
*********************************************************************/
double Instructor::getRating() {
    return rating;
}

/*********************************************************************
** Description:     virtual function that overrides the base class
**                  function that displays for how many hours an
**                  instructor graded paper
*********************************************************************/
void Instructor::do_work() {
    std::cout << getName() << " graded papers for "
              << generateHoursWorked() << " hours.\n\n";
}