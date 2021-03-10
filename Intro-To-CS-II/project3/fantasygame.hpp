/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: header file for fanatasyGame class



*/

#ifndef FANTASYGAME_HPP
#define FANTASYGAME_HPP

#include "menu.hpp"

#include "creature.hpp"
#include "vamp.hpp"
#include "barbarian.hpp"
#include "blueman.hpp"
#include "medusa.hpp"
#include "harry.hpp"

class FantasyGame
{
private:
    Creature* p1;
    Creature* p2;

    //game trackers
    int turn, rounds;

    //for internal use
    void chooseCreatures();
    void faceOff(Creature*, Creature*);
    void printStrength();

public:
    //constructor + destructor
    FantasyGame();

    //implements gameplay
    void play();

};

#endif // FANTASYGAME_HPP
