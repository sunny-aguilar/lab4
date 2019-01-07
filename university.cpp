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
