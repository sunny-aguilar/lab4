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
    university.addTwoBuildings();

    Menu menu;

    do {
        menu.mainMenu();
        menu.setSelection( menu.validateNumber(MENU_MIN, MENU_MAX) );
        if (menu.getSelection() == 1) {
            menu.buildingMenu();
            university.printBuildingInfo();
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 2) {
            menu.personMenu();
            university.printPersonInfo();
            // ENTER FUNCTIONS HERE TO PRINT PERSONS IN UNI CLASS


            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 3) {
            menu.workMenu();
            // ENTER FUNCTION HERE TO SET WORKER

            
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 4) {
            repeatMenu = false;
        }
        else {
            cout << "Error processing your menu choice!\n";
        }

    } while (repeatMenu);


    // test base class pointers to see if polymorphism is working
    Person *b = new Person;
    b->do_work();

    Person *p = new Student;
    p->do_work();

    Person *pp = new Instructor;
    pp->do_work();

    menu.exitMenu();

    return 0;
}