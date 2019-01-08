/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     Describe
**
**
**
*********************************************************************/
#include "university.hpp"

/*********************************************************************
** Description:     constructor that sets name to OSU
*********************************************************************/
University::University() {
    name = "Oregon State University";
}

/*********************************************************************
** Description:    adds a building object to vector
*********************************************************************/
void University::addBuilding(string name, int size, string address) {
    Building b;
    buildings.push_back(b.createBuilding(name, size, address));
}

/*********************************************************************
** Description:    returns a student object
*********************************************************************/
void University::addStudent(double gpa) {
    Person *s = new Student(gpa);
    person.push_back(s);
}


void University::addInstructor(double rating) {
    Instructor *i = new Instructor(rating);
    person.push_back(i);
}

void University::addPersons() {
    addStudent();
    addInstructor();
}

double University::generateGPA() {
    unsigned seed;
    double randomGPA;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomGPA = rand() % 4;
    cout << "GPA " << randomGPA << endl;
    return randomGPA;
}




/*********************************************************************
** Description:    prints building info
*********************************************************************/
void University::printBuildingInfo() {
    for (Building val: buildings) {
        cout << val.getBuildingName() << endl;
        cout << val.getBuildingSize() << endl;
        cout << val.getBuildingAddress() << endl << endl;
    }
}

/*********************************************************************
** Description:    adds two building objects inside of university
*********************************************************************/
void University::addTwoBuildings() {
    addBuilding("Kelley Engineering Center", 152166,
                    "110 SW PARK TERRACE\nCORVALLIS, OR 97331");
    addBuilding("Memorial Union Building", 166177,
                    "2501 SW JEFFERSON WAY\nCORVALLIS, OR 97331");
}

/*********************************************************************
** Description:    prints person info
*********************************************************************/
void University::printPersonInfo() {

}

/*********************************************************************
** Description:    gets building info with parameter specifying which
**                 building in the array
*********************************************************************/
Building University::getBuilding(vector<Building> vect, int sel) {
    return buildings[sel];
}