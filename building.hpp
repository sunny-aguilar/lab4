/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Building class creates buildings inside of the
**                  University class. Buildings is instantiated
**                  inside of the University object where two buildings
**                  are added at the start of the program. Each
**                  building is stored inside a vector. Building data
**                  members consist of a building name, building size
**                  and address.
*********************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
#include <vector>
using std::string;
using std::vector;

class Building {
public:
    Building();
    Building(string name, int size, string address);
    Building createBuilding(string name, int size, string address);
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
