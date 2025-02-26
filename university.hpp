/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     University class holds objects of the Person class
**                  and Building class as private variables. University
**                  class creates Building and Person objects, manages
**                  them, and gets the object information for display
**                  purposes. University class holds the the building
 *                  objects in a vector of type Building and the
 *                  Person objects are held as a vector of pointers
 *                  that point to Person objects. Objects are
 *                  dynamically created inside the University class
 *                  and de-allocated using the destructor inside of
 *                  the University class.
*********************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "menu.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

class University {
public:
    University();
    virtual ~University();
    void startSim();
    void programFlow();
    void addStudent(double gpa, string name, int age);
    void addInstructor(double rating, string name, int age);
    void printBuildings();
    void printPeople();
    void doWork();
    void addPersons();
    void addMorePersons();
    void readFromFile();
    double generateDouble(int max);
    int generateAge(int selectType);
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
    Menu menu;

};

#endif
