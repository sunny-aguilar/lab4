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

class Person {
public:
    void setName(std::string name);
    std::string getName();
    virtual void do_work();

private:
    std::string name;
    int age;
};

#endif
