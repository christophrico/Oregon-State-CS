/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Header file for Blue Man class. Derived from creature class

*/

#ifndef BLUEMAN_HPP
#define BLUEMAN_HPP

#include "creature.hpp"

class BlueMan : public Creature
{
public:
    //constructor and destructor
    BlueMan();
    virtual~BlueMan();

    //attack and defense functions implement fighting
    virtual int attack(string&);
    virtual int defend(int, string&, int&);
};

#endif // BLUEMAN HPP
