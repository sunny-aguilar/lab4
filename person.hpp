/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Person class is the base class for the Student
**                  class and Instructor class. Person class has
**                  various virtual functions that allow for
**                  polymorphic behavior. Person class does not have
**                  any pure virtual functions so it is not an abstract
**                  class.
*********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <ctime>
using std::string;

class Person {
public:
    Person();
    Person(string name, int age);
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    int generateHoursWorked();
    virtual void do_work();
    virtual double getGPA();
    virtual double getRating();

private:
    string name;
    int age;
};

#endif
