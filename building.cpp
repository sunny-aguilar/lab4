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
#include "building.hpp"

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
Building::Building(string name, int size, string address)
    : name{name}, size{size}, address{address} {
}

/*********************************************************************
** Description:    returns a new building object
*********************************************************************/
Building Building::createBuilding(string name, int size, string address) {
    Building tempBuilding(name, size, address);

    // code to get the data from the user goes here unless you
    // keep it like:
    // university.addBuild("Aguilar Building", 2000, "4369 Weathervane Way")

    return tempBuilding;
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