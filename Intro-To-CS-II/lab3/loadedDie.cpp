/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Implementation file for LoadedDie class
            **Child of Die class**
            Takes number of die sides as initialization argument
            Only method is "roll", which returns a biased random number between
            1 - # die sides.
            Compile with board.cpp, inputVal.cpp, and main.cpp
*/

#include "loadedDie.hpp"

LoadedDie::LoadedDie() : Die()
{}

//constructor, sets sides to user-input amount
LoadedDie::LoadedDie(int sides)
{
  this->numSides = sides;
}

//roll function to replace unbiased roll function
int LoadedDie::roll()
{
  int biasRoll = 0;

  //generate a biased random higher than average
  while(biasRoll <= 0 || biasRoll > this->numSides)
  {
      biasRoll = (randIntRange(1, this->numSides) + randIntRange(0, 3));

      if (biasRoll > this->numSides)
      {
        biasRoll = 0;
      }

      else
          return biasRoll;
  }
}
