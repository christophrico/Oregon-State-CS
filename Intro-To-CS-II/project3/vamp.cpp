/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for Vampire class - derived from creature
             Contains attack and defend functions:
             -Attack: Rolls 1 12-sided die to generate an attack amount
             -Defend: Rolls one 6-sided dice to generate a defense amount.
                      50/50 chance that the opponent's attack will not harm vampire
                      Then subtracts defense amount and armor from opposing player's attack

             Compile with creature.cpp, fantasygame.cpp

*/

#include "vamp.hpp"

//constructor, set specified name, armor, and strength
Vampire::Vampire() : Creature()
{
    name = "Vampire";
    armor = 1;
    strength = 18;
}

//destructor, just for deletability
Vampire::~Vampire()
{}

//attack, rolls 12-sided die to generate attack amount
int Vampire::attack(string& aS)
{
    aS = "";
    return randIntRange(1,12);
}

//defense, rolls 6-sided die to generate defense amount. 50/50 chance vamp is not hurt by attack
int Vampire::defend(int inAttack, string& dS, int& dR)
{
    // 50/50 chance of vampire not being hurt by attack
    int charm = randIntRange(0,1);
    int defense = randIntRange(1,6);
    dR = inAttack - (armor + defense);

    //if charm is turned on, no damage registered
    if (charm == 1)
    {
        dR = 0;
        dS = " used charm!";
    }

    //otherwise, normal harm occurs
    else if (charm == 0)
    {
        dS = "";

        if (dR > 0)
        {
            strength -= dR;
        }
    }

    return defense;
}
