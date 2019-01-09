/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     This program implements a simple information
**                  system that contains information about OSU.
**                  This program contains 5 classes. 
**
*********************************************************************/
#include "university.hpp"
#include "building.hpp"
#include "student.hpp"
#include "menu.hpp"
#include "instructor.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    // create constants and bool value
    const int MENU_MIN = 1;             // control menu selection
    const int MENU_MAX = 4;             // control menu selection
    bool repeatMenu = true;             // control menu

    // instantiate menu object
    Menu menu;
    // instantiate  a university object
    University university;

    // instantiate two buildings
    university.addTwoBuildings();
    // instantiate 1 student and 1 instructor
    university.addPersons();

    // loop controls menu
    do {
        // show main menu, validate & set selection
        menu.mainMenu();
        menu.setSelection( menu.validateNumber(MENU_MIN, MENU_MAX) );

        // select next menu option
        if (menu.getSelection() == 1) {
            // show menu building
            menu.buildingMenu();
            // show buildings
            university.printBuildingInfo();
            // show menu again & validate user input
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 2) {
            // user selects menu option two
            // show menu and display persons
            menu.personMenu();
            university.displayPerson();
            // display menu & validate
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 3) {
            // user selects menu option three
            // create an array to hold person names and sent it to
            // the menu object to display names of people to do work
            int totalPersons = university.getTotalPersons();
            vector<string> personNames;

            // store names in array
            for (int x = 0; x < university.getTotalPersons(); x++) {
                personNames.push_back(university.getPersonPointer(x)->getName());
            }
            // show menu with people to do work & validate user input
            menu.workMenu(totalPersons, personNames);
            menu.setSelection( menu.validateNumber(1,2) );

            // show selected person doing work
            university.displayPersonWorking( menu.getSelection() - 1 );

            // display menu & validate
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 4) {
            // user menu option 4 (exit program)
            repeatMenu = false;
        }
        else {
            cout << "Error processing your menu choice!\n";
        }

    } while (repeatMenu);

    // display exit menu
    menu.exitMenu();

    return 0;
}