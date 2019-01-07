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

#include <string>

class Person {
public:
    virtual void do_work();

private:
    std::string name;
    int age;
};

#endif
