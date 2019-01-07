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
using std::string;

class Building {
public:
    Building();
    Building(string name, int size, string address);
    Building addBuilding(string name, int size, string address);
    void setBuildingName(string name);
    void setBuildingSize(int size);
    void setBuildingAddress(string address);
    string getBuildingName();
    int getBuildingSize();
    string getBuildingAddress();

private:
    string name;
    int size;
    string address;
};

#endif
