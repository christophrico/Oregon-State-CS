/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Header file for barbarian class. Derived from creature class.

*/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.hpp"

class Barbarian : public Creature
{
public:
    //constructor and destructor
    Barbarian();
    virtual ~Barbarian();

    //implement attack and defense
    virtual int attack(string&);
    virtual int defend(int, string&, int&);
};

#endif // BARBARIAN HPP
