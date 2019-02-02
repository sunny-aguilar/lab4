/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
** Description:     Menu class is used to display menus and validate
**                  user input. This class is not part of a class
**                  hierarchy but works in conjunction with the
**                  University class to display the menus as needed.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Menu {
public:
    void setSelection(int sel);
    int getSelection();
    void mainMenu();
    void buildingMenu();
    void personMenu();
    void workMenu(int totalPersons, vector<string> vect);
    void backToMainMenu();
    void exitMenu();
    int validateNumber(int min, int max);

private:
    int selection;
};

#endif
