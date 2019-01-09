/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Student class instantiates objects of type Student
**                  and are assigned to a pointer that points to its
**                  base class data type. The Student class is a
**                  specialized version of the Person class since it
**                  holds information about students. This class has
**                  two virtual functions that override the behavior
**                  of the Person class functions.
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
