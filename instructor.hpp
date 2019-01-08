/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"
#include <iostream>

class Instructor : public Person {
public:
    Instructor();
    Instructor(double rating, string name, int age);
    void setRating(double rating);
    double getRating();
    void do_work();

private:
    double rating;
};

#endif
