/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for the Deep Playa derived class.

*/

#ifndef DEEPPLAYA_HPP
#define DEEPPLAYA_HPP

#include "space.hpp"

class DeepPlaya : public Space
{
public:
  //constructor and destructor
    DeepPlaya();
    virtual ~DeepPlaya();

    //pure virtual functions; must be implemented here
    virtual int getSteps(Space*);
    virtual void interact(Pack*);

};

#endif // DEEPPLAYA HPP
