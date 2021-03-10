/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Implementation file for Die object.
             Takes number of die sides as initization arguments.
             Only method is "roll", which returns an integer between
             1 - # sides.
             Compile with board.cpp, main.cpp, inputVal.cpp
*/

#include "die.hpp"

//default constructor, sets sides to 6
Die::Die()
{
  this -> numSides = 6;
}

//constructor, sets sides to user input amount
Die::Die(int sides)
{
    this -> numSides = sides;
}

//returns unbiased random number within range of sides
int Die::roll()
{
    return randIntRange(1, this->numSides);
}
