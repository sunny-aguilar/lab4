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
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class University {
public:
    University();
    Person *addStudent();
    void printBuildingInfo(int val);
    void addBuilding(string name, int size, string address);
    void addTwoBuildings();
    void printPersonInfo();
    Building getBuilding(vector<Building> vect, int sel);
    friend Menu::getPrintBuildingInfo();

private:
    std::string name;
    vector<Building> buildings;
    vector<Person *> person;

};

#endif
