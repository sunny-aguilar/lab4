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
    bool repeatMenu = true;

    University university;
    // instantiate two buildings
    university.addTwoBuildings();
    // instantiate 1 student and 1 instructor
    university.addPersons();


    Menu men;

    do {
        men.mainMenu();
        men.setSelection( men.validateNumber(MENU_MIN, MENU_MAX) );
        if (men.getSelection() == 1) {
            men.buildingMenu();
            university.printBuildingInfo();
            men.backToMainMenu();
            men.setSelection( men.validateNumber(1,2) );
            if (men.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (men.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (men.getSelection() == 2) {
            men.personMenu();
            university.displayPerson();
            men.backToMainMenu();
            men.setSelection( men.validateNumber(1,2) );
            if (men.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (men.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (men.getSelection() == 3) {
            // create an array to hold person names and sent it to
            // the menu to display names of people to do work
            int totalPersons = university.getTotalPersons();
            vector<string> personNames;
            for (int x = 0; x < university.getTotalPersons(); x++) {
                personNames.push_back(university.getPersonPointer(x)->getName());
            }
            men.workMenu(totalPersons, personNames);
            men.setSelection( men.validateNumber(1,2) );
            university.displayPersonWorking( men.getSelection() - 1 );
            men.backToMainMenu();
            men.setSelection( men.validateNumber(1,2) );
            if (men.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (men.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (men.getSelection() == 4) {
            repeatMenu = false;
        }
        else {
            cout << "Error processing your menu choice!\n";
        }

    } while (repeatMenu);


    // test base class pointers to see if polymorphism is working
//    Person *b = new Person;
//    b->do_work();
//
//    Person *p = new Student;
//    p->do_work();
//    p->getGPA();
//
//    Person *pp = new Instructor;
//    pp->do_work();

    men.exitMenu();

    return 0;
}