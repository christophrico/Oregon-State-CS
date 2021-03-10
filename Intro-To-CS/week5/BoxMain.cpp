//Boxmain.cpp - trying this shit out for the first time

#include <iostream>
#include "Box.hpp"

using namespace std;

int main()
{
  
  Box box1(10.8, 95.27, 7.0);
  Box box2;
  
  cout << "Parameters for box1 are 10.8, 95.27, 7.0. \n";
  cout << "And parameters for box2 are 2, 2.51, and 2. \n";
  
  box2.setLength(2);
  box2.setWidth(2.51);
  box2.setHeight(2);
  
  cout << endl;
  cout << "The surface area of box1 is " << box1.calcSurfaceArea() << endl;
  cout << "and the volume of box1 is " << box1.calcVolume() << endl << endl;
  cout << "The surface area of box2 is " << box2.calcSurfaceArea() << endl;
  cout << "and the volume of box2 is " << box2.calcVolume() <<endl;
  
  return 0;
}
