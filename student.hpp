/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "person.hpp"

class Student : public Person {
public:
    Student();
    Student(double gpa);
    void setGPA(double gpa);
    double getGPA();
    void do_work();

private:
    double gpa;
};

#endif
