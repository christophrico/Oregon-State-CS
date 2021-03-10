//board.hpp
/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: repeatArray program. Takes a reference to a pointer
to a dynamically allocated array, doubles it, then copies the values
into the array twice.
************************************************************/

#ifndef BOARD_H
#define BOARD_H
#include <iostream>

using namespace std;

enum Score {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
  char locations[3][3];

public:
  //default constructor
  Board();

  //setters
  bool makeMove(int, int, char);

  //getters
  Score gameState();
  void print();
};

#endif //VENDSLOT H
