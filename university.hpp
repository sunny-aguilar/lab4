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

#include "menu.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
using std::vector;
using std::cout;
using std::endl;

class University {
public:
    University();
    virtual ~University();
    void addStudent(double gpa, string name, int age);
    void addInstructor(double rating, string name, int age);
    void addPersons();
    double generateDouble();
    int generateAge();
    Person *getPersonPointer(int number);
    void displayPerson();
    void displayPersonWorking(int number);
    int getTotalPersons();
    void printBuildingInfo();
    void addBuilding(string name, int size, string address);
    void addTwoBuildings();
    Building getBuilding(vector<Building> vect, int sel);

private:
    std::string name;
    vector<Building> buildings;
    vector<Person *> person;

};

#endif
