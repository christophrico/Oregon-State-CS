//Box.cpp

/************************************************************************************
** Author: Christopher Rico
** Date:5/3/17
** Description: Week 5 assignment. Implementation file for box class
* that makes a box object. Has set functions setWidth, setLength, and setHeight.
* Has get/calculate functions calcSurfaceArea, calcVolume. Accepts 3 doubles as parameters.
***********************************************************************************/

#include "Box.hpp"

//user-defined parameter constructor
Box::Box(double h, double w, double l)
{
  height = h;
  width = w;
  length = l;
}

void Box::setHeight(double inputHeight)
{
  height = inputHeight;
}

void Box::setWidth(double inputWidth)
{
  width = inputWidth;
}

void Box::setLength(double inputLength)
{
  length = inputLength;
}

double Box::calcVolume()
{
  return (length*width*height);
}

double Box::calcSurfaceArea()
{
  return 2*((width*length) + (height*length) + (height*width));
}
