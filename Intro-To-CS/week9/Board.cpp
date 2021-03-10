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
  //check row, column, and digaonals for X or O wins
  if (checkRow() == X_WON || checkCol() == X_WON || checkDiag() == X_WON)
    return X_WON;

  if (checkRow() == O_WON || checkCol() == O_WON || checkDiag() == O_WON)
    return O_WON;

  //check for a draw
  int count = 0;
  for (int row = 0; row<3; row++)
  {
    for (int col = 0; col<3; row++)
      if(locations[row][col] == 'x' || locations[row][col] == 'o');
        count++;
  }
  //if all spots are taken, game is a DRAW
  if (count == 9)
    return DRAW;
  else
    return UNFINISHED;
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

Score Board::checkRow()
{
  int count = 0;
  //check each of the three rows
  for (int row = 0; row < 3; row++)
  {
    count = 0;
    for (int col = 0; col < 3; col++)
    {
      //if x's are there, add one to count
      if (locations[row][col] == 'x')
      count++;
      //if o's are there, subtract one from count
      if (locations[row][col] == 'o')
      count--;
    }
    //if count equals 3 or -3, then x or o won, respectively
    if (count == 3)
      return X_WON;

    if (count == -3)
      return O_WON;
    }
}

Score Board::checkCol()
{
  //check each of the three columns
  for (int col = 0; col < 3; col++)
  {
    int  count = 0;
    for (int row = 0; row < count; row++)
    {
      //if x's are there, add one to count
      if (locations[row][col] == 'x')
      count++;
      //if o's are there, subtract one from count
      if (locations[row][col] == 'o')
      count--;
    }
    //if count equals 3 or -3, then x or o won, respectively
    if (count == 3)
      return X_WON;

    if (count == -3)
      return O_WON;
  }
}

Score Board::checkDiag()
{
  //check left-to-right down diagonal
  int count = 0;
  for (int col = 0; col < 3; col++)
  {
    //same setup as above loops
    if (locations[col][col] == 'x')
      count++;
    if (locations[col][col] == 'o')
      count--;
  }
  if (count == 3)
    return X_WON;
  if (count == -3)
    return O_WON;

  //check left-to-right up diagonal
  count = 0;
  for (int col = 0; col < 3; col++)
  {
    //same setup as above loops
    if (locations[col][2-col] == 'x')
      count++;
    if (locations[col][2-col] == 'o')
      count--;
  }
  if (count == 3)
    return X_WON;
  if (count == -3)
    return O_WON;
}
