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

class Instructor : public Person {
public:
    Instructor();
    Instructor(double rating, string name, int age);
    void setRating(double rating);
    virtual void do_work();
    virtual double getRating() override;


private:
    double rating;
};

#endif
