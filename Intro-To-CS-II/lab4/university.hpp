/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Header file for university class
*/

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "inputVal.hpp"
#include "student.hpp"
#include "person.hpp"
#include "instructor.hpp"
#include "building.hpp"

#include <vector>

class University
{
private:
    vector <Person*> people;
    vector <Building> buildings;

public:
    University();
    ~University();

    void printBldgs();
    void printPpl();

    void chooseWork();

};

#endif // UNIVERSITY H
