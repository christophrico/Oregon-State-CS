/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for Blue Man class - derived from creature
             Contains attack and defend functions:
             -Attack: Rolls two 10-sided dice to generate an attack amount
             -Defend: Rolls three 6-sided dice to generate a defense amount.
                      For each 4 strength points lost, one die is lost.
                      Then subtracts defense amount and armor from opposing player's attack

             Compile with creature.cpp, fantasygame.cpp

*/

#include "blueman.hpp"

//default constructor, sets name, armor and strength to default values
BlueMan::BlueMan() : Creature()
{
    name = "Blue Men";
    armor = 3;
    strength = 12;
}


BlueMan::~BlueMan()
{}


//attack function, rolls two 10-sided 'dice' to generate an attack
int BlueMan::attack(string& aS)
{
    return ( randIntRange(1,10) + randIntRange(1,10) );
}

//defense function, rolls 3 6-sided dice to generate a defense.
int BlueMan::defend(int inAttack, string& dS, int& dR)
{
    int defense;

    //every 4 points they lose, a die in defense is lost
    //three dice
    if (strength > 8)
    {
        dS = "";
        defense = ( randIntRange(1,6) + randIntRange(1,6) + randIntRange(1,6) );
        dR = inAttack - (armor + defense);
    }

    //two dice
    else if (strength <= 8 && strength > 4)
    {
        defense = ( randIntRange(1,6) + randIntRange(1,6) );
        dS = " suffer Mob damage! Only 2 defense dice to roll!";
        dR = inAttack - (armor + defense);
    }

    //one dice
    else
    {
        defense = randIntRange(1,6);
        dS = " suffer extreme Mob damage! Only 1 defense die to roll!";
        dR = inAttack - (armor + defense);
    }

    //as long as total damage is above 0, subtract it from strength
    if (dR > 0)
    {
        strength -= dR;
    }

    return defense;
}
