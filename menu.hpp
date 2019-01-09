/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void menuControl();
    void setSelection(int sel);
    int getSelection();
    void mainMenu();
    void buildingMenu();
    void personMenu();
    void workMenu(int totalPersons);
    void backToMainMenu();
    void exitMenu();
    int validateNumber(int min, int max);

private:
    int selection;
};

#endif
