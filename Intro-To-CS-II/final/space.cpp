/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for Space base class. This is an abstract class
             and must be implemented in its derived classes.
             Creates a space that is linked to four other spaces by pointer.

             Compile with: inputVal.cpp, deepplaya.cpp, distrikt.cpp, man.cpp,
             nineoclock.cpp, rv.cpp, temple.cpp, pack.cpp

*/

#include "space.hpp"

//constructor, sets all space pointers, name, and ID number to null values
Space::Space()
{
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    ID = 0;
    name = "null";
}

Space::~Space()
{}

//each of these functions returns a pointer to the adjacent space objects
Space* Space::toN()
{
    return north;
}

Space* Space::toS()
{
    return south;
}

Space* Space::toE()
{
    return east;
}

Space* Space::toW()
{
    return west;
}


//returns the name
string Space::getName()
{
    return name;
}

//returns the ID number
int Space::getID()
{
    return ID;
}

//allows for the adjacent spaces to be set
void Space::setAdj(Space* n, Space* s, Space* e, Space* w)
{
    north = n;
    south = s;
    east = e;
    west = w;
}

//pure virtual function, MUST be implemented in derived class
//returns the step distance between this space and another
int Space::getSteps(Space* nextSpace)
{
    return 0;
}

//pure virtual function, MUST be implemented in derived class
//allows the player to interact with the space and the items stored in the pack
void Space::interact(Pack* stuff)
{}
