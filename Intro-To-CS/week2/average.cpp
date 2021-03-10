/************************************************************************************
** Author: Christopher Rico
** Date: 4/12/17
** Description: Week 2 assignment. Program that gives average of five numbers.
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
  double numberOne, // numberOne through numberFive are user input
         numberTwo,
         numberThree,
         numberFour,
         numberFive,
         averageOfFive; // averageOfFive is the calculated average to be printed

  cout << "Please enter five numbers. \n";
  
  cin >> numberOne;
  cin >> numberTwo;
  cin >> numberThree;
  cin >> numberFour;
  cin >> numberFive;
  
  averageOfFive = (numberOne+numberTwo+numberThree+numberFour+numberFive)/5; // calculating the average
  
  cout << "The average of those numbers is: \n" << averageOfFive <<  endl; // printing the average to screen
  
  return 0;
}
