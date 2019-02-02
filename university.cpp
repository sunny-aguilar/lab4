/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2, 2019
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
** Description:     start university program simulation
*********************************************************************/
void University::startSim() {
    addTwoBuildings();      // add two buildings
    addPersons();           // add two persons
    programFlow();          //begin with program
}

/*********************************************************************
** Description:     controls program logic. User is prompted to
 *                  select choices from the menu. Constant variables
 *                  are used to control menu options.
*********************************************************************/
void University::programFlow() {
    // create constants and bool value
    const int MENU_MIN = 1;             // control menu selection
    const int MENU_MAX = 6;             // control menu selection
    bool repeatMenu = true;             // control menu

    // loop controls menu
    do {
        // show main menu, validate & set selection
        menu.mainMenu();
        menu.setSelection( menu.validateNumber(MENU_MIN, MENU_MAX) );

        // select next menu option
        if (menu.getSelection() == 1) {
            // show menu building
            menu.buildingMenu();
            // show buildings
            printBuildingInfo();
            // show menu again & validate user input
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 2) {
            // user selects menu option two
            // show menu and display persons
            menu.personMenu();
            displayPerson();
            // display menu & validate
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 3) {
            // user selects menu option three
            // create an array to hold person names and sent it to
            // the menu object to display names of people to do work
            int totalPersons = getTotalPersons();
            vector<string> personNames;

            // store names in array
            for (int x = 0; x < getTotalPersons(); x++) {
                personNames.push_back(getPersonPointer(x)->getName());
            }
            // show menu with people to do work & validate user input
            menu.workMenu(totalPersons, personNames);
            menu.setSelection( menu.validateNumber(1,2) );

            // show selected person doing work
            displayPersonWorking( menu.getSelection() - 1 );

            // display menu & validate
            menu.backToMainMenu();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects main menu
                repeatMenu = true;
            }
            else if (menu.getSelection() == 2) {
                // user selects to exit program
                repeatMenu = false;
            }
        }
        else if (menu.getSelection() == 4) {
            // display menu to add more people
            menu.addMorePeople();
            menu.setSelection( menu.validateNumber(1,2) );
            if (menu.getSelection() == 1) {
                // user selects to add students
                double gpa = 0.0;
                string name;
                int age;

                // get student name
                cout << "Add Student to System:\n";
                cout << "Enter Student Name\n";
                cout << ">> ";
                getline(cin, name);

                // get student GPA
                cout << "Enter the student's G.P.A (0.0 - 4.0)\n";
                cout << ">> ";
                gpa = menu.validateDecimal("GPA",48,52,48,57);

                // get student age
                cout << "Enter Student's Age\n";
                cout << ">> ";
                age = menu.validateNumber(14, 100);

                // add student in array
                Person *s = new Student(gpa, name, age);
                person.push_back(s);

            }
            else if (menu.getSelection() == 2) {
                // user selects to add instructors
                double rating = 0.0;
                string name;
                int age;

                // get Instructor name
                cout << "Add Instructor to System:\n";
                cout << "Enter Instructor's Name\n";
                cout << ">> ";
                getline(cin, name);

                // get Instructor rating
                cout << "Enter the Instructor's Rating (0.0 - 5.0)\n";
                cout << ">> ";
                rating = menu.validateDecimal("Rating",48,53,48,57);

                // get Instructor age
                cout << "Enter Instructor's Age\n";
                cout << ">> ";
                age = menu.validateNumber(28, 100);

                // add Instructor in array
                Person *s = new Instructor(rating, name, age);
                person.push_back(s);
            }

        }
        else if (menu.getSelection() == 5) {
            // read in data from file
            menu.menuReadFile();

            // creating necessary variables
            string fileName;
            ifstream inFile;
            string outFileName;

            int selection = menu.validateNumber(1,5);
            if (selection == 1) {
                // add buildings from file
                cout << "Enter Building File Name\n";



            }
            else if (selection == 2) {
                // add students from file
                cout << "Enter Student File Name\n";



            }
            else if (selection == 3) {
                // add instructors from file
                cout << "Enter Instructor File Name\n";

            }
            else if (selection == 4) {
                // exit to main menu


            }
            else {
                cout << "Unable to determine file to read!\n";
            }
        }
        else if (menu.getSelection() == 6) {
            // user menu option 4 (exit program)
            repeatMenu = false;
        }
        else {
            cout << "Error processing your menu choice!\n";
        }
        cout << endl;
    } while (repeatMenu);

    // display exit menu
    menu.exitMenu();
}

/*********************************************************************
** Description:    adds a building object to a vector
*********************************************************************/
void University::addBuilding(string name, int size, string address) {
    Building b;
    buildings.push_back(b.createBuilding(name, size, address));
}

/*********************************************************************
** Description:     adds a pointer to a student object to the vector
 *                  of pointers
*********************************************************************/
void University::addStudent(double gpa, string name, int age) {
    Person *s = new Student(gpa, name, age);
    person.push_back(s);
}

/*********************************************************************
** Description:     adds a pointer to an instructor object to the
**                  vector of pointers
*********************************************************************/
void University::addInstructor(double rating, string name, int age) {
    Instructor *i = new Instructor(rating, name, age);
    person.push_back(i);
}

/*********************************************************************
** Description:    adds a student and instructor object when called
*********************************************************************/
void University::addPersons() {
    addStudent( generateDouble(4), "James Jameson", generateAge(1) );
    addInstructor( generateDouble(5), "Jill Joy", generateAge(2) );
}

/*********************************************************************
** Description:    EXTRA CREDIT - adds more people during runtime
*********************************************************************/
void University::addMorePersons() {

}

/*********************************************************************
** Description:     returns a random number from 0 to a max value
**                  given by the parameter passed in; used for getting
**                  a GPA and or rating.
*********************************************************************/
double University::generateDouble(int max) {
    int randomNum;
    randomNum = rand() % max + 1;
    return randomNum;       // return a random double from 1 to max
}

/*********************************************************************
** Description:     returns a random age from a prepopulated list of
**                  age groups that is randomly selected and returned.
**                  Parameter is used to select what type of person
**                  to generate number for.
*********************************************************************/
int University::generateAge(int selectType) {
    int randomAge = 0;
    int randomNum = 0;
    int studentAge[] = {18,19,20,21,22,23,24,30,31,32,33,34,35,36,37};
    int teacherAge[] = {28,30,34,38,30,44,48,50,54,58,60,64,68,70,74};
    randomNum = rand() % 14 + 1;
    switch (selectType) {
        case 1:
            randomAge = studentAge[randomNum];
            break;
        case 2:
            randomAge = teacherAge[randomNum];
            break;
        default:
            cout << "Error generating an age\n";
    }
    return randomAge;       // return age
}

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
** Description:     display person info for all people in the Person
**                  vector. Dynamic cast is used to get the object
**                  data type being pointed to by the base class
**                  pointer.
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

/*********************************************************************
** Description:     displays person doing work by taking in a
**                  parameter that selects the appropriate object
**                  and then calling the virtual do_work() function
*********************************************************************/
void University::displayPersonWorking(int number) {
    getPersonPointer(number)->do_work();
}

/*********************************************************************
** Description:    prints building info
*********************************************************************/
void University::printBuildingInfo() {
    for (Building val: buildings) {
        cout << val.getBuildingName() << endl;
        cout << val.getBuildingAddress() << endl;
        cout << val.getBuildingSize() << " sq. feet" << endl << endl;
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