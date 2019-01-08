/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "menu.hpp"
#include "university.hpp"
#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    const int MENU_MIN = 1;
    const int MENU_MAX = 4;

    University university;
    university.addTwoBuildings();

    Menu menu;
    menu.mainMenu();


    if (menu.validateNumber(1,4) == 1) {
        menu.buildingMenu();
        menu.backToMainMenu();
    }
    else if (menu.validateNumber(1,4) == 2) {

    }
    else if (menu.validateNumber(1,4) == 3) {

    }
    else if (menu.validateNumber(1,4) == 4) {

    }
    else {
        cout << "Error processing your menu choice!\n";
    }



    // building tests show buildings and add buildings
//    cout << building.getBuildingName() << endl;
//    cout << building.getBuildingSize() << endl;
//    cout << building.getBuildingAddress() << endl;
//    university.addBuilding("Aguilar Building", 2000, "4369 Weathervane Way");
//    university.addBuilding("Wesley Building", 2017, "4369 Weathervane Way");
//    university.printBuildingInfo();        // prints building name
//    university.printBuildingInfo();        // prints building name



    // test base class pointers to see if polymorphism is working
    Person *b = new Person;
    b->do_work();

    Person *p = new Student;
    p->do_work();

    Person *pp = new Instructor;
    pp->do_work();



    return 0;
}