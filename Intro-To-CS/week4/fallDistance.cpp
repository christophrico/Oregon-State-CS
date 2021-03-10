/**********************************************************
** Author: Christopher Rico
** Date: 4/26/17
** Description: Week 4 assignment. Function that calculates
* the distance an object falls in a given time.
************************************************************/

#include <iostream>
using namespace std;

double fallDistance(double fallTime) //returns a double, has a double as argument
{
    double fallDist;
    
    fallDist = (9.8*(fallTime*fallTime))/2;  //formula for distance fallen under pull of gravity
    
    return fallDist;
}


int main()
{
  double time, distance;
  
  cout << "Please enter a time in seconds: \n";
  cin >> time;
    
  distance = fallDistance(time);
    
  cout << distance << endl;
    
  return 0;
}

