/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
using std::string;

class Person {
public:
    Person();
    Person(string name, int age);
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    virtual void do_work();
    virtual double getGPA();
    virtual double getRating();

private:
    std::string name;
    int age;
};

#endif
