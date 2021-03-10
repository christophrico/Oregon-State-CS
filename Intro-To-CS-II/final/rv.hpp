/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for RV derived class

*/

#ifndef RV_HPP
#define RV_HPP

#include "space.hpp"

class RV : public Space
{
public:
    //constructor and destructor
    RV();
    virtual ~RV();

    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);

};

#endif // RV HPP
