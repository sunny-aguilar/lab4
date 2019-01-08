/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include <string>
#include <vector>
using std::vector;

class University {
public:
    University();
    Person *addStudent();
    void printBuildingInfo();
    void addBuild(string name, int size, string address);
    void printPersonInfo();
    void getBuilding(int select);

private:
    std::string name;
    vector<Building> buildings;
    vector<Person *> person;

};

#endif
