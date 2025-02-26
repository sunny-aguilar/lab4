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

        // select next menu option - Print Building Info
        if (menu.getSelection() == 1) {
            printBuildings();
        }
        else if (menu.getSelection() == 2) {
            // user selects menu option two - Print student & staff info
            printPeople();
        }
        else if (menu.getSelection() == 3) {
            // user selects menu option three - Choose a person to do work
            doWork();
        }
        else if (menu.getSelection() == 4) {
            // user selects menu option four - Extra Credit: Add more people
            addMorePersons();
        }
        else if (menu.getSelection() == 5) {
            // // user selects menu option five - Extra Credit: Read data from file
            readFromFile();
        }
        else if (menu.getSelection() == 6) {
            // user menu option 4 - (exit program)
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
** Description:     prints building information
*********************************************************************/
void University::printBuildings() {
    // show menu building
    menu.buildingMenu();
    // show buildings
    printBuildingInfo();
}

/*********************************************************************
** Description:     prints students and instructor info
*********************************************************************/
void University::printPeople() {
    // show menu and display persons
    menu.personMenu();
    displayPerson();
}

/*********************************************************************
** Description:     function chooses a person to do work. Person
**                  chosen is polymorphic since the context of the
**                  pointer will determine the virtual function chosen
*********************************************************************/
void University::doWork() {
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

/*********************************************************************
** Description:     EXTRA CREDIT - allows a user to add buildings and
**                  persons from a text file and output it to a text
**                  file. Three different files are used to read in
**                  the data for the buildings, students, and
**                  instructors. Three different files are outputted
**                  for the buildings, students and instructors.
**                  Building file name: building_list.txt
**                  Student file name: student_list.txt
**                  Instructor filename: instructor_list.txt
*********************************************************************/
void University::readFromFile() {
    // read in data from file
    menu.menuReadFile();

    // create necessary variables
    string fileName;
    ifstream inFile;
    string outFileName;

    // let user select which data to populate from file
    int selection = menu.validateNumber(1,5);
    if (selection == 1) {
        // add buildings from file
        cout << "Enter Building File Name (i.e. building_list.txt)\n";

        // loop - ask user for file name if incorrect
        do {
            cin >> fileName;                        // building_list.txt
            inFile.open(fileName);                  // input file data from building_list.txt
            if (inFile.fail())
                cout << "File not found! "          // request file name if not found
                     << "Enter a file name:\n";
        } while (inFile.fail());                    // if file not found, repeat loop

        // confirm input file opened
        cout << "Building file successfully opened\n";

        // data variables for buildings
        string data;
        string name;
        string address;
        int size;
        int count = 0;

        // add building file to OSU database
        while (getline(inFile, data)) {
            count++;
            if (count == 1) {
                name = data;
            }
            if (count == 2) {
                address = data;
            }
            if (count == 3) {
                size = stoi(data);
                count = 0;
                addBuilding(name, size, address);
            }
        }
        cout << "\nBuildings have been added to the OSU database\n\n";

        // save building file list
        ofstream outFile;

        // request output file name for each paragraph
        cout << "\nEnter a file name to save building data (i.e. updated_buildings.txt):\n";
        cout << ">> ";
        cin >> outFileName;

        // create/overwrite output file object
        outFile.open(outFileName);

        // output building info to file
        for (Building val: buildings) {
            outFile << val.getBuildingName() << endl;
            outFile << val.getBuildingAddress() << endl;
            outFile << val.getBuildingSize() << endl;
        }

        // close output file
        outFile.close();

    }
    else if (selection == 2) {
        // add students from file
        cout << "Enter Student File Name (i.e. student_list.txt)\n";

        // loop - ask user for file name if incorrect
        do {
            cin >> fileName;                        // student_list.txt
            inFile.open(fileName);                  // input file data from student_list.txt
            if (inFile.fail())
                cout << "File not found! "          // request file name if not found
                     << "Enter a file name:\n";
        } while (inFile.fail());                    // if file not found, repeat loop

        // confirm input file opened
        cout << "Student file successfully opened\n";

        // data variables for students
        string data;
        string name;
        double gpa = 0.0;
        int age = 0;
        int count = 0;

        // add student file to OSU database
        while (getline(inFile, data)) {
            count++;
            if (count == 1) {
                name = data;
            }
            if (count == 2) {
                gpa = stod(data);
            }
            if (count == 3) {
                age = stoi(data);
                count = 0;
                addStudent(gpa, name, age);
            }
        }
        cout << "\nStudents have been added to the OSU database\n\n";

        // save student file list
        ofstream outFile;

        // request output file name for each paragraph
        cout << "\nEnter a file name to save student data (i.e. updated_students.txt):\n";
        cout << ">> ";
        cin >> outFileName;

        // create/overwrite output file object
        outFile.open(outFileName);

        // output student info to file
        for (int student = 0; student < person.size(); student++) {
            if (dynamic_cast<Student*>(getPersonPointer(student))) {
                outFile << getPersonPointer(student)->getName() << endl;
                outFile << fixed << setprecision(1) << getPersonPointer(student)->getGPA() << endl;
                outFile << getPersonPointer(student)->getAge() << endl;
            }
        }

        // close output file
        outFile.close();
    }
    else if (selection == 3) {
        // add instructors from file
        cout << "Enter Instructor File Name (i.e. instructor_list.txt)\n";

        // loop - ask user for file name if incorrect
        do {
            cin >> fileName;                        // instructor_list.txt
            inFile.open(fileName);                  // input file data from instructor_list.txt
            if (inFile.fail())
                cout << "File not found! "          // request file name if not found
                     << "Enter a file name:\n";
        } while (inFile.fail());                    // if file not found, repeat loop

        // confirm input file opened
        cout << "Instructor file successfully opened\n";

        // data variables for students
        string data;
        string name;
        double rating = 0.0;
        int age = 0;
        int count = 0;

        // add instructor file to OSU database
        while (getline(inFile, data)) {
            count++;
            if (count == 1) {
                name = data;
            }
            if (count == 2) {
                rating = stod(data);
            }
            if (count == 3) {
                age = stoi(data);
                count = 0;
                addInstructor(rating, name, age);
            }
        }
        cout << "\nInstructors have been added to the OSU database\n\n";

        // save instructor file list
        ofstream outFile;

        // request output file name for each paragraph
        cout << "\nEnter a file name to save instructor data (i.e. updated_instructors.txt):\n";
        cout << ">> ";
        cin >> outFileName;

        // create/overwrite output file object
        outFile.open(outFileName);

        // output instructor info to file
        for (int instructor = 0; instructor < person.size(); instructor++) {
            if (dynamic_cast<Instructor*>(getPersonPointer(instructor))) {
                outFile << getPersonPointer(instructor)->getName() << endl;
                outFile << fixed << setprecision(1) << getPersonPointer(instructor)->getRating() << endl;
                outFile << getPersonPointer(instructor)->getAge() << endl;
            }
        }

        // close output file
        outFile.close();
    }
    else if (selection == 4) {
        // exit to main menu


    }
    else {
        cout << "Unable to determine file to read!\n";
    }
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
    addBuilding("KELLEY ENGINEERING CENTER", 152166,
                    "110 SW PARK TERRACE CORVALLIS, OR 97331");
    addBuilding("MEMORIAL UNION BUILDING", 166177,
                    "2501 SW JEFFERSON WAY CORVALLIS, OR 97331");
}

/*********************************************************************
** Description:    gets building info with parameter specifying which
**                 building in the array
*********************************************************************/
Building University::getBuilding(vector<Building> vect, int sel) {
    return buildings[sel];
}