/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Project 1
Description: Client code for matrix assignment. Asks user to select
			 a 2x2 or 3x3 matrix, then allocates the array for the
			 matrix. Calls a function to fill the matrix,
			 then another function to get the determinate of the
			 matrix. Then, it de-allocates the array.

			 Compile with readMatrix.cpp, determinate.cpp
*/

#include "ant.hpp"

    //constructor for user input of ant loc and board size
    Ant::Ant(int xA, int yA, int xB, int yB)
    {
        //record starting values of ant
        antX = xA;
        antY = yA;
        boardX = xB;
        boardY = yB;

        //set board size and where the ant is starting
        antBoard.setSize(xB, yB);
        antBoard.setAnt(xA, yA);
    }

    //returns the next direction of the ant
    //based on the current direction, next cell color
    char Ant::calcNextDirection(char CD, char CSC)
    {
        //if cell is black, which direction will ant go?
        if (CSC == '#')
        {
          switch (CD)
          {
            case 'N': return 'W';
                      break;
            case 'W': return 'S';
                      break;
            case 'S': return 'E';
                      break;
            case 'E': return 'N';
                      break;
          }
        }

        //if cell is white, which direction will ant go?
        else if (CSC == ' ')
        {
          switch (CD)
          {
            case 'N': return 'E';
                      break;
            case 'E': return 'S';
                      break;
            case 'S': return 'W';
                      break;
            case 'W': return 'N';
                      break;
          }
        }
      }

    //returns next x based on current x and direction
    int Ant::calcNextX(int CX, char CD_X)
    {
      //if ant is going north
      if (CD_X == 'N')
      {
        //and hits the edge, 'loop' to other side
        if(CX == 0)
          return (boardX - 1);
        //otherwise, move one north
        else
          return (CX - 1);
      }

      //if ant is going south
      else if (CD_X == 'S')
      {
        //and hit the edge, 'loop' him to other side
        if (CX == (boardX - 1))
          return (0);
        //otherwise, move one south
        else
          return (CX + 1);
      }

      //if ant isn't moving north or south, don't change his x.
      else
        return CX;
    }

    //returns next y based on current y and direction
    int Ant::calcNextY(int CY, char CD_Y)
    {
      //if ant is moving west
      if (CD_Y == 'W')
      {
        //and he hits the edge of the board, 'loop' to other side
        if(CY == 0)
          return (boardY - 1);
        //otherise, move one west
        else
          return (CY - 1);
      }

      //if ant is moving east
      else if (CD_Y == 'E')
      {
        //and hits the edge of the board, 'loop' to other side
        if (CY == (boardY - 1))
          return (0);
        //otherwise, move one east
        else
          return (CY + 1);
      }

      //if ant isn't moving east or west, don't change y
      else
        return CY;
    }

   //moves ant to next cell based on algorithm
    void Ant::moveAnt()
    {
        //first print the board
        system("clear");
        antBoard.printBoard();

        //ask board what color next cell is, save info
        nextSquareCol = antBoard.getColor(calcNextX(antX, currentAntDir),
                                          calcNextY(antY, currentAntDir));

        //calculate the next direction the ant will take
        nextAntDir = calcNextDirection(currentAntDir, nextSquareCol);

        //assign ant to next cell
        antBoard.setAnt(calcNextX(antX, currentAntDir),
                        calcNextY(antY, currentAntDir));

        //flip current square to opposite of what it was
        antBoard.changeSquareColor(antX, antY, currentSquareCol);

        //set ant coordinates to new values
        antX = calcNextX(antX, currentAntDir);
        antY = calcNextY(antY, currentAntDir);

        //save color of current square and direction for use in next loop
        currentSquareCol = nextSquareCol;
        currentAntDir = nextAntDir;

    }
