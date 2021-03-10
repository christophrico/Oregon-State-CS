/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for Man derived class

*/

#ifndef MAN_HPP
#define MAN_HPP

#include "space.hpp"

class Man : public Space
{
public:
    //constructor and destructor
    Man();
    virtual ~Man();
    
    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);
};

#endif // MAN HPP
