/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

class Building {
public:
    Building();
    Building addBuilding();

private:
    std::string name;
    int size;
    std::string address;
};

#endif
