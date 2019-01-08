/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/

#include "menu.hpp"

void Menu::menuControl() {
    mainMenu();
    switch ( validateNumber(1,4) ) {
        case 1:
            buildingMenu();
            getPrintBuildingInfo();
            break;
        case 2:
            personMenu();
            break;
        case 3:
            workMenu();
            break;
        case 4:
            exitMenu();
            break;
        default:
            cout << "Error processing your menu choice\n";
    }
}

/*********************************************************************
** Description:     displays the main menu
*********************************************************************/
void Menu::mainMenu() {
    cout << "OREGON STATE UNIVERSITY INFORMATION SYSTEM\n";
    cout << "1. Print Building Info\n";
    cout << "2. Print Student & Staff Info\n";
    cout << "3. Choose a Person to do Work\n";
    cout << "4. Exit the Program\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays menu to print building info
*********************************************************************/
void Menu::buildingMenu() {
    cout << "Printing all building info\n";
}

/*********************************************************************
** Description:     displays menu to print people info
*********************************************************************/
void Menu::personMenu() {
    cout << "Printing all people info\n";
}

/*********************************************************************
** Description:     displays menu to chose a person to do work
*********************************************************************/
void Menu::workMenu() {
    cout << "Choose a person to do work\n";
}

/*********************************************************************
** Description:     displays the exit program menu
*********************************************************************/
void Menu::exitMenu() {
    cout << "Exiting the program\n";
}


/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}


void Menu::getPrintBuildingInfo() {

}