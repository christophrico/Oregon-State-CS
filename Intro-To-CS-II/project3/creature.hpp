/*
Name:		      Christopher Rico
OSU ID:		    933239746
Date:		      8/6/17
Assignment:	  CS 162 - Project 3
Description:  Header file for creature base class

*/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "inputVal.hpp"

class Creature
{
protected:
    int strength,
        armor;

    string name;

public:
    //constructor and destructor
    Creature();
   virtual ~Creature();

   //getters
   int getStrength();
   int getArmor();
   string getName();

   //setters
   void setStrength(int);
   void setArmor(int);
   void setName(string);

   //attack/defend functions. Pure virtual - MUST be implemented in derived classes
   virtual int attack(string&) = 0;
   virtual int defend(int, string&, int&) = 0;
};

#endif // CREATURE HPP
