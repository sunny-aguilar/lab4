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

Instructor::Instructor(double rating) : rating{rating} { }

void Instructor::do_work() {
    std::cout << "Doing instructor work!\n";
}