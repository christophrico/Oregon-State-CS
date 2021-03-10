/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for Harry Potter class - derived from creature
             Contains attack and defend functions:
             -Attack: Rolls two 6-sided dice to generate an attack amount
             -Defend: Rolls twp 6-sided dice to generate a defense amount.
                      Then subtracts defense amount and armor from opposing player's attack.
                      If Harry's strength drops below 0, then he regains his
                      strength up to 20 points!

             Compile with creature.cpp, fantasygame.cpp


*/

#include "harry.hpp"


//default constructor, sets name, armor, strength, and deaths values to default values
Harry::Harry() : Creature()
{
    name = "Harry Potter";
    armor = 0;
    strength =10;
    deaths = 0;
}

Harry::~Harry()
{}


//attack function, rolls two 6-sided dice to generate an attack amount
int Harry::attack(string& aS)
{
    aS = "";
    return ( randIntRange(1,6) + randIntRange(1,6) );
}

//defend function, rolls two 6-sided dice to generate a defense amount
//if Harry's strength drops below 0, strength is regained up to 20
int Harry::defend(int inAttack, string& dS, int& dR)
{
    int defense = ( randIntRange(1,6) + randIntRange(1,6) );
    dR = inAttack - (armor + defense);

    dS = "";

    //as long as damage taken is above 0, subtract it from strength
    if (dR > 0)
    {
        strength -= dR;
    }

    //if harry's strength drops to 0, he gets 20 strength points back!
    if (strength <= 0 && deaths == 0)
    {
        deaths++;
        strength = 20;
        dR = 0;
        dS = " used Hogwarts! Strength powered up to 20!";
    }

    return defense;
}
