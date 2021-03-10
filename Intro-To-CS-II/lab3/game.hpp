/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Header file for Game class.
*/

#ifndef GAME_H
#define GAME_H

#include "loadedDie.hpp"
#include <iomanip>

using namespace std;

class Game
{
private:
    char player1Type,
         player2Type;

    int rounds,
        player1Score,
        player1Sides,
        player2Score,
        player2Sides,
        **results;

    const int MAX_SIDES = 30,
              MIN_SIDES = 4;

    Die *d1, *d2;

    //private methods for in-class use
    void compDie(int);
    void printGame();
    void makeArray();

public:
   //default constructor, initalizes scores to 0
    Game();
    //implements game play
    void playGame();
    //destructor, deletes score array and dynamically allocated die objs
    ~Game();
};

#endif //GAME_H
