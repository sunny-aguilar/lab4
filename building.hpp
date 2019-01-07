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
    Building addBuilding();
    void setBuildingName(string name) { this->name = name; }
    void setBuildingSize(int size) { this->size = size; }
    void setBuildingAddress(::string address) { this->address = address; }
    string getBuildingName();
    int getBuildingSize();
    string getBuildingAddress();

private:
    string name;
    int size;
    string address;
};

#endif
