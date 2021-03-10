/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for temple derived class.

*/

#ifndef TEMPLE_HPP
#define TEMPLE_HPP

#include "space.hpp"

class Temple : public Space
{
public:
    //constructor and destructor
    Temple();
    virtual ~Temple();

    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);

};

#endif // TEMPLE HPP
