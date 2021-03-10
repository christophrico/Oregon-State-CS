//tictactoe.cpp

/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: repeatArray program. Takes a reference to a pointer
to a dynamically allocated array, doubles it, then copies the values
into the array twice.
************************************************************/

#include "TicTacToe.hpp"


//constructor that takes player to start as param
TicTacToe::TicTacToe(char firstPlayer)
{
  turn = firstPlayer;
}

//private method that swaps player turn, returns opposite
char TicTacToe::swapTurn(char playerToSwap)
{
  if (playerToSwap == 'X')
    return 'O';

  else
    return 'X';
}

//mutator method that implements game play
void TicTacToe::play()
{
  while(tic.gameState() == UNFINISHED)
  {
    //print board and prompt first player for their move
    cout << endl << "Player " << turn << ": please enter your move." << endl;
    cin >> row >> col;

    //if the move is valid, record it and print the board.
    if(tic.makeMove(row, col, turn))
    {
      cout << endl;
      tic.print();
      cout << endl;
      //then swap the player
      turn = swapTurn(turn);
    }

    //if the space isn't open, print the board
    //and restart the loop without swapping players
    else
    {
      cout << "That square is already taken." << endl;
      cout << endl;
      tic.print();
      cout << endl;
    }
  }

  //once gameState isn't "UNFINISHED", cout
  //who won, or if the game is a draw
  cout << endl << "The game has finished! The result is: ";

  if (tic.gameState() == X_WON)
	cout << endl << "X_WON" << endl;;
  if (tic.gameState() == O_WON)
	cout << endl << "O_WON" << endl;
  if (tic.gameState() == DRAW)
	cout << endl << "DRAW" << endl;;
}

int main()
{
  char firstMove;

  cout << "Welcome to Tic-Tac-Toe!" << endl;
  cout << "Please enter an X or a O to indicate" << endl;
  cout << "which player would like to begin:" << endl;
  cin >> firstMove;

  //create TicTacToe object
  TicTacToe mainTac(firstMove);

  //let TicTacToe object run the game and print the result
  mainTac.play();

  return 0;
}
