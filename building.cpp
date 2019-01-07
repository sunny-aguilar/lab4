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

Building::Building() {

}

Building::Building(std::string name, int size, std::string address)
    : name{name}, size{size}, address{address} {
}

//Building Building::addBuilding() {
//
//}