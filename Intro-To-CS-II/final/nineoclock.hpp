/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for Nine O Clock derived class

*/

#ifndef NineOClock_HPP
#define NineOClock_HPP

#include "space.hpp"

class NineOClock : public Space
{
public:
  //constructor and destructor
    NineOClock();
    virtual ~NineOClock();

    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);

};

#endif // NineOClock HPP
