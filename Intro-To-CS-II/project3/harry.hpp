/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Header file for Harry Potter class. Derived from creature class.

*/

#ifndef HARRY_HPP
#define HARRY_HPP

#include "creature.hpp"

class Harry : public Creature
{
private:
    int deaths;

public:
    //constructor and destructor
    Harry();
    virtual ~Harry();

    //attack and defense functions, implement fighting
    virtual int attack(string&);
    virtual int defend(int, string&, int&);
};

#endif // HARRY HPP
