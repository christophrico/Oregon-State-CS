/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Header file for Die object
*/

#ifndef DIE_H
#define DIE_H

#include "inputVal.hpp"

class Die
{
protected:
    int numSides;

 public:
    //default constructor
    Die();
    //constructor for specifying number of sides
    Die(int);

    //returns random number within range of sides
    virtual int roll();
};

#endif //DIE_H
