/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Header file for vampire class. Derived from creature class

*/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "creature.hpp"

class Vampire : public Creature
{
public:
    //constructor and destructor
    Vampire();
    virtual ~Vampire();

    //fight implementation
    virtual int attack(string&);
    virtual int defend(int, string&, int&);
};

#endif // VAMPIRE HPP
