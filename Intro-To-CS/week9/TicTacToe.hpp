//tictactoe.hpp

/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: repeatArray program. Takes a reference to a pointer
to a dynamically allocated array, doubles it, then copies the values
into the array twice.
************************************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.hpp"

class TicTacToe
{
private:
  Board tic;
  char turn;
  int row, col;

  //private method to swap the player
  char swapTurn(char);

public:
  //constructor, takes first player as param
  TicTacToe(char);
  //mutator method that implements game play
  void play();

};

#endif // BOARD H
