/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Implementation file for LoadedDie class
             **Child of Die**
*/

#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "die.hpp"

class LoadedDie : public Die
{

public:
    //default constructor
    LoadedDie();
    //constructor for user-input sides
    LoadedDie(int);
    int roll();

};

#endif //LOADEDDIE_H
