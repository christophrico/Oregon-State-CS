/*
Name:		      Christopher Rico
OSU ID:		    933239746
Date:		      8/6/17
Assignment:	  CS 162 - Project 3
Description:  Creature base class. This is an abstract function that must be
              implemented by each derived class.
              Creature provides the get/set methods for the two data members,
              strength and armor.
              Also has two pure virtual methods, attack and defend,
              that must be implemented uniquely in derived classes

              Compile with inputVal.cpp menu.cpp fantasygame.cppcreature.cpp vamp.cpp
              barbarian.cpp blueman.cpp medusa.cpp harry.cpp
*/


#include "creature.hpp"

//default constructor, not implemented
Creature::Creature()
{}

//default destructor, not implemented
Creature::~Creature()
{}

//returns strength int
int Creature::getStrength()
{
    return strength;
}

//returns armor int
int Creature::getArmor()
{
    return armor;
}

//returns name string
string Creature::getName()
{
    return name;
}


//sets strength int
void Creature::setStrength(int s)
{
    strength = s;
}

//sets strength int
void Creature::setArmor(int a)
{
    armor = a;
}

//sets name string
void Creature::setName(string n)
{
    name = n;
}


//pure virtual functions, must be implemented in derived classes
int Creature::attack(string& )
{
    return 0;
}

int Creature::defend(int, string&, int&)
{
    return 0;
}
