//Taxicab.cpp

/************************************************************************************
** Author: Christopher Rico
** Date:5/3/17
** Description: Week 5 assignment. Implementation file for taxicab class
* that makes a taxicab object. Has get functions getXCoord, getYCoord, and getDistanceTraveled.
* Has mutate functions moveX, moveY. Accepts 2 doubles as parameters.
***********************************************************************************/

#include "Taxicab.hpp"
#include <cmath>

//user-defined parameter constructor
Taxicab::Taxicab(int initialX, int initialY)
{
  x = initialX;
  y = initialY;
  totalDist = 0;
}

int Taxicab::getXCoord()
{
  return x;
}

int Taxicab::getYCoord()
{
  return y;
}

int Taxicab::getDistanceTraveled()
{
  return totalDist;
}

void Taxicab::moveX(int distXMoved)
{
  x += distXMoved;
  totalDist += std::abs(distXMoved);
}

void Taxicab::moveY(int distYMoved)
{
  y += distYMoved;
  totalDist += std::abs(distYMoved);
}