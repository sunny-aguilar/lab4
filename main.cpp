/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "university.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <iostream>

int main() {

    University university;
    Person person;

    Person *p = new Student;
    p->do_work();

    Person *pp = new Instructor;
    pp->do_work();



    return 0;
}