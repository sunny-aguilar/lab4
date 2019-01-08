/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "university.hpp"
#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {

    University university;
    Building building("Kelley Engineering Center", 152166,
                      "110 SW PARK TERRACE\nCORVALLIS, OR 97331");
//    Person person;

    // building tests
//    cout << building.getBuildingName() << endl;
//    cout << building.getBuildingSize() << endl;
//    cout << building.getBuildingAddress() << endl;
    university.addBuild("Aguilar Building", 2000, "4369 Weathervane Way");
    university.addBuild("Wesley Building", 2017, "4369 Weathervane Way");




    // test base class pointers to see if polymorphism is working
    Person *b = new Person;
    b->do_work();

    Person *p = new Student;
    p->do_work();

    Person *pp = new Instructor;
    pp->do_work();



    return 0;
}