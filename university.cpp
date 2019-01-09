/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     University class holds objects of the Person class
**                  and Building class as private variables. University
**                  class creates Building and Person objects, manages
**                  them, and gets the object information for display
**                  purposes. University class holds the the building
 *                  objects in a vector of type Building and the
 *                  Person objects are held as a vector of pointers
 *                  that point to Person objects. Objects are
 *                  dynamically created inside the University class
 *                  and de-allocated using the destructor inside of
 *                  the University class.
*********************************************************************/
#include "university.hpp"

/*********************************************************************
** Description:     constructor that sets name to OSU
*********************************************************************/
University::University() {
    name = "Oregon State University";
}

/*********************************************************************
** Description:     destructor that de-allocates the vector of
**                  pointers to Person objects.
*********************************************************************/
University::~University() {
    for (auto &val: person) {
        delete val;
    }
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

/*********************************************************************
** Description:    returns an instructor object
*********************************************************************/
void University::addInstructor(double rating, string name, int age) {
    Instructor *i = new Instructor(rating, name, age);
    person.push_back(i);
}

/*********************************************************************
** Description:    adds a student and instructor object when called
*********************************************************************/
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
    return randomNum;

//    unsigned seed;
//    int randomNum;
//    double randomGPA[] = {0.0, 1.0, 2.0, 3.0, 4.0};
//    seed = static_cast<unsigned int>(time(nullptr));
//    srand(seed);
//    randomNum = rand() % 4 + 1;
//    return randomGPA[randomNum];
}

/*********************************************************************
** Description:     returns a random age from a prepopulated list of
**                  age groups that is randomly selected and returned
*********************************************************************/
int University::generateAge(int selectType) {
    unsigned seed;
    int randomAge;
    int studentAge[] = {18,19,20,21,22,23,24,30,31,32,33,34,35,36,37};
    int teacherAge[] = {28,30,34,38,30,44,48,50,54,58,60,64,68,70,74};
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomAge = rand() % 14 + 1;
    switch (selectType) {
        case 1:
            randomAge = studentAge[randomAge];
            break;
        case 2:
            randomAge = studentAge[];
            break;
        default:
            cout << "Error generating an age\n";
    }
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