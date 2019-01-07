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
    void do_work();
private:
    double rating;
};

#endif
