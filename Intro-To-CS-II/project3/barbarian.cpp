/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for barbarian class - derived from creature
             Contains attack and defend functions:
             -Attack: Rolls two 6-sided dice to generate an attack amount
             -Defend: Rolls two 6-sided dice to generate a defense amount. Then
                      subtracts defense amount and armor from opposing player's attack

             Compile with creature.cpp, fantasygame.cpp

*/

#include "barbarian.hpp"


//default constructor, sets name, armor, and strength to default values
Barbarian::Barbarian() : Creature()
{
    name = "Barbarian";
    armor = 0;
    strength = 12;
}

//destructor
Barbarian::~Barbarian()
{}

//attack function, generates an attack value
int Barbarian::attack(string& aS)
{
    aS = "";
    //rolls two 6-sided 'dice'
    return ( randIntRange(1,6) + randIntRange(1,6) );
}


//defend function, generates a defense value and sets strength according to recieved attack
int Barbarian::defend(int inAttack, string& dS, int& dR)
{
  //rolls two 6-sided dice to generate attack value
  int defense = ( randIntRange(1,6) + randIntRange(1,6) );
  //amount of damage is attack value - armor - defense roll
  dR = inAttack - (armor + defense);

  dS = "";

  //as long as damage is above 0, subtract it from strength
  if (dR > 0)
      strength -= dR;

  return defense;
}
