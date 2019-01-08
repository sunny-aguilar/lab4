/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "university.hpp"
#include "student.hpp"

/*********************************************************************
** Description:     constructor that sets name to OSU
*********************************************************************/
University::University() {
    name = "Oregon State University";
}

/*********************************************************************
** Description:    adds a building object to vector
*********************************************************************/
void University::addBuild(string name, int size, string address) {
    Building b;
    buildings.push_back(b.addBuilding(name, size, address));
}

/*********************************************************************
** Description:    returns a student object
*********************************************************************/
Person *University::addStudent() {
    Person *s = new Student;
    return s;
}

/*********************************************************************
** Description:    prints building info
*********************************************************************/
void University::printBuildingInfo() {

}

/*********************************************************************
** Description:    prints person info
*********************************************************************/
void University::printPersonInfo() {

}

/*********************************************************************
** Description:    gets building info with parameter specifying which
**                 building in the array
*********************************************************************/
void getBuilding(int sel) {
    buildings[sel];
}