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
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

class Instructor : public Person {
public:
    Instructor();
    Instructor(double rating, string name, int age);
    void setRating(double rating);
    virtual void do_work() override;
    virtual double getRating() override;


private:
    double rating;
};

#endif
