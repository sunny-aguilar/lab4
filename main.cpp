/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     This program implements a simple information
**                  system that contains information about OSU.
**                  This program contains 5 classes. University class
**                  has two embedded classes (Building class & Person
**                  class) as private members. The Person class has
**                  a hierarchy where the Student class and Instructor
**                  class are derived from the Person class.
*********************************************************************/
#include "university.hpp"
#include "building.hpp"
#include "student.hpp"
#include "menu.hpp"
#include "instructor.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);            // create random number seed
    University university;  // create University object
    university.startSim();  // start the program
    return 0;
}