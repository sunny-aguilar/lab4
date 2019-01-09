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
    Student(double gpa, string name, int age);
    void setGPA(double gpa);
    virtual void do_work() override;
    virtual double getGPA() override;

private:
    double gpa;
};

#endif
