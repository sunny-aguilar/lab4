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

#include "university.hpp"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void menuControl(University obj);
    void mainMenu();
    void buildingMenu();
    void personMenu();
    void workMenu();
    void exitMenu();
    int validateNumber(int min, int max);

    void getPrintBuildingInfo(University &obj);

private:

};

#endif
