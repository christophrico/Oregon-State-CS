//Taximain.cpp - trying this shit out for the first time

#include <iostream>
#include "Taxicab.hpp"

using namespace std;

int main()
{
  int userX, userY;
  
  Taxicab taxi1(15, 7);
  Taxicab taxi2;
  
  cout << "Please declare how many x and y you would like taxi2 to move. \n";
  cin >> userX;
  cin >> userY;
  
  taxi2.moveX(userX);
  taxi2.moveY(userY);

  taxi1.moveY(-10);
  taxi1.moveX(-45);
  taxi1.moveX(23);

  taxi2.moveY(2);

  cout << endl;
  cout << "Taxi 1 is at position " << taxi1.getXCoord();
  cout << ", " << taxi1.getYCoord() << endl;
  cout <<"With a total distance traveled of " << taxi1.getDistanceTraveled() << endl;
  cout << "And Taxi 2 is at position " << taxi2.getXCoord();
  cout << ", " << taxi2.getYCoord() << endl;
  cout <<"With a total distance traveled of " << taxi2.getDistanceTraveled() << endl;

  return 0;
}