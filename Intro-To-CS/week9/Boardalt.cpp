//board.cpp
/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: repeatArray program. Takes a reference to a pointer
to a dynamically allocated array, doubles it, then copies the values
into the array twice.
************************************************************/

#include "Board.hpp"
//default constructor, sets board to empty
Board::Board()
{
  for (int row = 0; row<3; row++)
  {
    for (int col = 0; col<3; col++)
      locations[row][col] = '.';
  }
}

bool Board::makeMove(int rowIn, int colIn, char player)
{
  if (locations[rowIn][colIn] == '.')
  {
    if (player == 'O')
      locations[rowIn][colIn] = 'o';

    else
      locations[rowIn][colIn] = 'x';

    return true;
  }

  else
    return false;
}

Score Board::gameState()
{
  Score outcome = UNFINISHED;

  //check rows
  for (int row = 0; row < 3; row++)
  {
      if (locations[row][0] == locations[row][1] &&
          locations[row][1] == locations[row][2])
        {
          if (locations[row][0] == 'x')
            outcome = X_WON;
          if (locations[row][0] == 'o')
            outcome = O_WON;
        }
  }

  //check columns
  for (int col = 0; col < 3; col++)
  {
      if (locations[0][col] == locations[1][col] &&
          locations[0][col] == locations[2][col])
        {
          if (locations[0][col] == 'x')
            outcome = X_WON;
          if (locations[0][col] == 'o')
            outcome = O_WON;
        }
  }

  //check left-to-right down diag
  if (locations[0][0] == locations[1][1] &&
      locations[0][0] == locations[2][2])
    {
      if (locations[0][0] == 'x')
        outcome = X_WON;
      if (locations[0][0] == 'o')
        outcome = O_WON;
    }
  //check left-to-right up diag
  if (locations[0][2] == locations[1][1] &&
      locations[0][2] == locations[2][0])
    {
      if (locations[0][2] == 'x')
        outcome = X_WON;
      if (locations[0][2] == 'o')
        outcome = O_WON;
    }

  int drawCount = 0;
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
      {
        if(locations[row][col] == 'x' || locations[row][col] == 'o')
           drawCount++;
      }
  }
  //if all spots are taken, game is a DRAW
  if (drawCount == 9)
    outcome = DRAW;

    return outcome;
}

void Board::print()
{
  cout << "  0 1 2 " << endl;

  for (int row = 0; row<3; row++)
  {
    cout << row << " ";

    for (int col = 0; col<3; col++)
      cout << locations[row][col] << " ";

    cout << endl;
  }
}
