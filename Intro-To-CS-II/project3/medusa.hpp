/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Header file for Medusa class. Derived from creature class.

*/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "creature.hpp"

class Medusa : public Creature
{
public:
    //constructor and destructor
    Medusa();
    virtual ~Medusa();

    //attack and defend functions implement fighting
    virtual int attack(string&);
    virtual int defend(int, string&, int&);
};

#endif // MEDUSA HPP
