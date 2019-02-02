/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Menu class is used to display menus and validate
**                  user input. This class is not part of a class
**                  hierarchy but works in conjunction with the
**                  University class to display the menus as needed.
*********************************************************************/
#include "menu.hpp"

/*********************************************************************
** Description:     sets selection member variable
*********************************************************************/
void Menu::setSelection(int sel) {
    selection = sel;
}

/*********************************************************************
** Description:     gets selection member variable
*********************************************************************/
int Menu::getSelection() {
    return selection;
}

/*********************************************************************
** Description:     displays the main menu
*********************************************************************/
void Menu::mainMenu() {
    cout << "OREGON STATE UNIVERSITY INFORMATION SYSTEM\n";
    cout << "1. Print Building Info\n";
    cout << "2. Print Student & Staff Info\n";
    cout << "3. Choose a Person to do Work\n";
    cout << "4. EXTRA CREDIT - Add More People\n";
    cout << "5. Exit the Program\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays menu to print building info
*********************************************************************/
void Menu::buildingMenu() {
    cout << "\n- Printing building info -\n";
}

/*********************************************************************
** Description:     displays menu to print people info
*********************************************************************/
void Menu::personMenu() {
    cout << "\n- Printing Student and Instructor info -\n";
}

/*********************************************************************
** Description:     EXTRA CREDIT - prompts user to add more people at
**                  runtime
*********************************************************************/
void Menu::addMorePeople() {
    cout << "\n- Add More Students and Instructors -\n";
    cout << "1. Add Student\n";
    cout << "2. Add Instructor\n";
    cout << ">> ";
}

/*********************************************************************
** Description:     displays menu to chose a person to do work
*********************************************************************/
void Menu::workMenu(int totalPersons, vector<string> vect) {
    cout << "Choose a person to do work\n";
    for (int i = 0; i < totalPersons; i++) {
        cout << i+1 << ". Choose " << vect[i] << "\n";
    }
}

void Menu::backToMainMenu() {
    cout << "1. Enter 1 for Main Menu\n";
    cout << "2. Enter 2 to Exit Program\n";
    cout << ">> ";
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
        for (unsigned i = 0; i < strlen(choice); i++) {
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

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
double Menu::validateNumber(string rating, char min1, char max1, char min2, char max2) {
    char choice[100];
    bool tooLong = false;
    bool decimalFound = false;
    bool decOneRange = false;
    bool decTwoRange = false;
    bool perfectScore = false;
    std::stringstream convert;
    double validatedNumber = 0.0;

    do {
        // reset bool values
        tooLong = false;
        decimalFound = false;
        decOneRange = false;
        decTwoRange = false;
        perfectScore = false;

        // get user value
        cout << "Enter " << rating <<  ": ";
        cin.getline(choice, 100);

        // check if value entered is longer than 3 characters 0.0
        if (strlen(choice) > 3 && !tooLong) {
            tooLong = true;
            cout << rating << " entered is too long\n";
        }

        // check if decimal found in user input
        if (choice[1] == '.') {
            decimalFound = true;
        }

        // check range
        if (choice[0] >= 48 && choice[0] <= max2) {
            decOneRange = true;
            // if user has perfect rating, limit decimal value to 0
            if (choice[0] == max2) {
                min2 = 48;
                max2 = 48;
                perfectScore = true;
            }
        }

        // let user know that GPA/Rating cannot exceed limits (4.0/5.0)
        if (perfectScore && (choice[2] > min2)) {
            cout << rating << " entered cannot exceed 4.0 for students and";
            cout << " 5.0 for Instructors\n";
            decTwoRange = false;
        }
        else {
            if (choice[2] >= 48 && choice[2] <= 57) {
                decTwoRange = true;
            }

            if (tooLong) {
                cout << rating << " format must be be entered as 0.0\n";
            }

            if (!decOneRange || !decTwoRange) {
                cout << "Value entered cannot exceed 4.0 for Students and";
                cout << " 5.0 for Instructors\n";
            }
        }

        // return validated decimal number
        if (!tooLong && decimalFound && decOneRange && decTwoRange) {
            convert << choice;
            convert >> validatedNumber;
        }

    } while (tooLong || !decimalFound || !decOneRange || !decTwoRange);

    // return validated double
    return validatedNumber;
}