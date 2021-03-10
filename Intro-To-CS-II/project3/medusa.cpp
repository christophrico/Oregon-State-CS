/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for Medusa class - derived from creature
             Contains attack and defend functions:
             -Attack: Rolls two 6-sided dice to generate an attack amount.
                      If a roll of 12, then Medusa attacks 30 points and kills
                      opposing player.
             -Defend: Rolls two 6-sided dice to generate a defense amount.

             Compile with creature.cpp, fantasygame.cpp


*/

#include "medusa.hpp"

//constructor, sets name, armor, and strength to specified values
Medusa::Medusa() : Creature()
{
    name = "Medusa";
    armor = 3;
    strength = 8;
}

Medusa::~Medusa()
{}

//attack, rolls 2 6-sided dice. If roll of 12 is made, then opposing player loses
int Medusa::attack(string& aS)
{
    //glare is two '6-sided dice' rolled
    int glare = ( randIntRange(1,6) + randIntRange(1,6) );

    //if medusa rolls a 12, she uses glare and kills the other character
    if (glare == 12)
    {
        aS = "used glare! Her opponent was turned to stone.";
        return 30;
    }

    //otherwise, just return her attack roll
    else
    {
        aS = "";
        return glare;
    }
}


//defend, rolls two 6-sided dice to generate defense amount
int Medusa::defend(int inAttack, string& dS, int& dR)
{
    //generate a random defense roll between 1 and 6
    int defense = randIntRange(1,6);
    dR = inAttack - (armor + defense);

    dS = "";

    if (dR > 0)
    {
        strength -= dR;
    }

    return defense;


}
