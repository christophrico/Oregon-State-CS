/****************************************************************
** Author: Christopher Rico
** Date: 4/26/17
** Description: Week 4 assignment. Hailstone function that counts
* the number of steps to reach 1.
******************************************************************/

#include <iostream>
using namespace std;

int hailstone(int seedNum) //returns an integer, the argument is an integer
{
  int tries = 0;
  
  while (seedNum != 1) //as long as our number is not one do this
  {
    if (seedNum %  2  == 0)  //if number is even, divide it by two
        seedNum /= 2;
    else
        seedNum = ((seedNum * 3) + 1); //if number is odd, mult by 3 and add 1
  tries++;  // count how many steps it took
  }

  return tries;
}


int main()
{
  int startNum, steps;
    
  cout << "Enter a starting number:" << endl;
  cin >> startNum;
    
  steps = hailstone(startNum);
  cout << "It took " << steps << " # of steps to get there." << endl;

  return 0;
}

