/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for the player class. This class implements gameplay.

*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "menu.hpp"

#include "space.hpp"
#include "nineoclock.hpp"
#include "deepplaya.hpp"
#include "distrikt.hpp"
#include "rv.hpp"
#include "temple.hpp"
#include "man.hpp"

class Player
{
private:
    //pointers to space objects. These create the linked game structure
    Space *currentSpace,
           *dis,
           *dp,
           *noc,
           *man,
           *rv,
           *tem;

    //container for user to store items
    Pack* fannypack;
    int stepsRemaining;
    //private methods for in-class gameplay
    void printSteps();
    void moveSpace();

public:
    //constructor and destructor, create linked spaces at game instantiation
    //and delete them when the game terminates
    Player();
    ~Player();

    //presents menu to user to control game
    void playGame();
};

#endif // PLAYER HPP
