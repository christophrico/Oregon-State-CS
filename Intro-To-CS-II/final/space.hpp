/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for Space base class. Space is abstract.

*/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "menu.hpp"
#include "pack.hpp"
#include "art.hpp"

class Space
{
protected:
    //pointers to other space objects, create linked gamespace
    Space *north, *south, *east, *west;
    string name;
    int ID;

public:
    //constructor and destructor
    Space();
    virtual ~Space();

    //return the adjacent space in each direction
    Space* toN();
    Space* toS();
    Space* toE();
    Space* toW();

    //returns the name
    string getName();
    //returns the ID
    int getID();

    //allows for adjacent spaces to be assigned
    void setAdj(Space*, Space*, Space*, Space*);

    //pure virtual functions, MUST be implemented in each derived class
    virtual int getSteps(Space*) = 0;
    virtual void interact(Pack*) = 0;
};

#endif // SPACE HPP
