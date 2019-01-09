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
    addStudent( generateDouble(4), "James Jameson", generateAge() );
    addInstructor( generateDouble(5), "Jill Joy", generateAge() );
}

/*********************************************************************
** Description:     returns a random number from 0 to a max value
**                  given by the parameter passed in; used for getting
**                  a GPA and or rating.
*********************************************************************/
double University::generateDouble(int max) {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % max + 1;
    double randomGPA[] = {0.0, 1.0, 2.0, 3.0, 4.0};
    return randomGPA[randomNum];
}

int University::generateAge() {
    unsigned seed;
    int randomAge;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomAge = rand() % (70 - 18 + 1) + 18;
    return randomAge;
}

// WRITE A FUNCTION TO ASK FOR A USER NAME AND ENTER UP ABOVE IN LINE 41 AND 42



Person *University::getPersonPointer(int number) {
    return person[number];
}

/*********************************************************************
** Description:    display person info
*********************************************************************/
void University::displayPerson() {
    for (int x = 0; x < person.size(); x++) {
        cout << "Name: " << getPersonPointer(x)->getName() << endl;
        cout << "Age:" << getPersonPointer(x)->getAge() << endl;

        if (dynamic_cast<Student*>(getPersonPointer(x))) {
            cout << "GPA: " << getPersonPointer(x)->getGPA() << endl;
        }
        else if (dynamic_cast<Instructor*>(getPersonPointer(x))) {
            cout << "Rating: " << getPersonPointer(x)->getRating() << endl;
        }

//        if ( getPersonPointer(x)->getGPA() ) {
//            cout << "GPA: " << getPersonPointer(x)->getGPA() << endl;
//        }
//        else if ( getPersonPointer(x)->getRating() ) {
//            cout << "Rating: " << getPersonPointer(x)->getRating() << endl;
//        }

        getPersonPointer(x)->do_work();
        cout << endl;
    }
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