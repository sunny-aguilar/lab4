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
    addStudent( generateDouble(), "James Jameson", generateAge() );
    addInstructor( generateDouble(), "Jill Joy", generateAge() );
}

/*********************************************************************
** Description:     returns a random number from 0 to a max value
**                  given by the parameter passed in; used for getting
**                  a GPA and or rating.
*********************************************************************/
double University::generateDouble() {
    unsigned seed;
    int randomNum;
    double randomGPA[] = {0.0, 1.0, 2.0, 3.0, 4.0};
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % 4 + 1;
    return randomGPA[randomNum];
}

int University::generateAge() {
    unsigned seed;
    int randomNum;
    int age[] = {18,19,20,21,22,23,33,36,43,46,53,56,63,68,70};
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % 14 + 1;
    return age[randomNum];
}

// WRITE A FUNCTION TO ASK FOR A USER NAME AND ENTER UP ABOVE IN LINE 41 AND 42


/*********************************************************************
** Description:    gets the person pointer from the vector
*********************************************************************/
Person *University::getPersonPointer(int number) {
    return person[number];
}

/*********************************************************************
** Description:    gets the total people in the person vector
*********************************************************************/
int University::getTotalPersons() {
    return person.size();
}

/*********************************************************************
** Description:    display person info
*********************************************************************/
void University::displayPerson() {
    for (int x = 0; x < person.size(); x++) {
        cout << std::fixed << std::setprecision(1);
        if (dynamic_cast<Student*>(getPersonPointer(x))) {
            cout << "Student Name: " << getPersonPointer(x)->getName() << endl;
            cout << "Student GPA: " << getPersonPointer(x)->getGPA() << endl;
            cout << "Student Age: " << getPersonPointer(x)->getAge() << endl;
        }
        else if (dynamic_cast<Instructor*>(getPersonPointer(x))) {
            cout << "Instructor Name: " << getPersonPointer(x)->getName() << endl;
            cout << "Instructor Rating: " << getPersonPointer(x)->getRating() << endl;
            cout << "Instructor Age: " << getPersonPointer(x)->getAge() << endl;
        }
        cout << endl;
    }
}

void University::displayPersonWorking(int number) {
    getPersonPointer(number)->do_work();
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
** Description:    gets building info with parameter specifying which
**                 building in the array
*********************************************************************/
Building University::getBuilding(vector<Building> vect, int sel) {
    return buildings[sel];
}