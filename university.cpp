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
void University::addStudent(double gpa, string name, int age) {
    Person *s = new Student(gpa, name, age);
    person.push_back(s);
}


void University::addInstructor(double rating, string name, int age) {
    Instructor *i = new Instructor(rating, name, age);
    person.push_back(i);
}

void University::addPersons() {
    addStudent( generateDouble(4.0), "", generateAge() );
    addInstructor( generateDouble(5.0), "", generateAge() );
}

/*********************************************************************
** Description:     returns a random number from 0 to a max value
**                  given by the parameter passed in
*********************************************************************/
double University::generateDouble(int max) {
    unsigned seed;
    double randomGPA;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomGPA = rand() % max + 1;
    return randomGPA;
}

int University::generateAge() {
    unsigned seed;
    int randomGPA;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomGPA = rand() % (70 - 18 + 1) + 18;
    return randomGPA;
}

// WRITE A FUNCTION TO ASK FOR A USER NAME AND ENTER UP ABOVE IN LINE 41 AND 42



Person *University::getPersonPointer(int number) {
    return person[number];
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