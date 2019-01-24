# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	January 2019
# Description:	Makefile for Lab 4 University
# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += university.o
OBJECTS += menu.o
OBJECTS += building.o
OBJECTS += person.o
OBJECTS += student.o
OBJECTS += instructor.o

HPPs = university.hpp
HPPs += menu.hpp
HPPs += building.hpp
HPPs += person.hpp
HPPs += student.hpp
HPPs += instructor.hpp

CPPs = main.cpp
CPPs += university.cpp
CPPs += menu.cpp
CPPs += building.cpp
CPPs += person.cpp
CPPs += student.cpp
CPPs += instructor.cpp

# Targets needed to bring the executable up to date
lab4: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o lab4 $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

menu.o: menu.hpp

building.o: building.hpp

person.o: person.hpp

student.o: student.hpp

instructor.o: instructor.hpp

# Clean-up operations
clean:
	rm lab4 *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./lab4

zip:
	zip -D Lab4_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt
