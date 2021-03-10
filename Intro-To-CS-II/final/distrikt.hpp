/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for the Distrikt derived class

*/

#ifndef DISTRIKT_HPP
#define DISTRIKT_HPP

#include "space.hpp"

class Distrikt : public Space
{
public:
    //constructor and destructor
    Distrikt();
    virtual ~Distrikt();

    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);

};

#endif // DISTRIKT HPP
