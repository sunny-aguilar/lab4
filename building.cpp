/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "building.hpp"
#include <string>

/*********************************************************************
** Description:     default constructor that sets building member
**                  variables to empty or zero
*********************************************************************/
Building::Building() : name{}, size{0}, address{} { }

/*********************************************************************
** Description:     3-arg constructor that sets building member
**                  variables to values passed in via parameters
**                  during initialization.
*********************************************************************/
Building::Building(std::string name, int size, std::string address)
    : name{name}, size{size}, address{address} {
}

/*********************************************************************
** Description:    returns a new building object
*********************************************************************/
Building Building::addBuilding(std::string name, int size, std::string address) {
    Building b = new Building(name, size, address);

    return b;
}

/*********************************************************************
** Description:    set building name
*********************************************************************/
void Building::setBuildingName(string name) {
    this->name = name;
}

/*********************************************************************
** Description:    set building size
*********************************************************************/
void Building::setBuildingSize(int size) {
    this->size = size;
}

/*********************************************************************
** Description:    set building address
*********************************************************************/
void Building::setBuildingAddress(string address) {
    this->address = address;
}

/*********************************************************************
** Description:    set building name
*********************************************************************/
string Building::getBuildingName() {
    return name;
}

/*********************************************************************
** Description:    set building size
*********************************************************************/
int Building::getBuildingSize() {
    return size;
}

/*********************************************************************
** Description:    set building address
*********************************************************************/
string Building::getBuildingAddress() {
    return address;
}