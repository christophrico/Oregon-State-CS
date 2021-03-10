/************************************************************************************
** Author: Christopher Rico
** Date: 4/12/17
** Description: Week 2 assignment. Program that asks the user for a number of cents
* (between 0 and 99) and returns the number of each type of coin that represents that
* amount with the fewest total number of coins.
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int cents,
      quarters,
      dimes,
      nickels,
      pennies;
      
  cout << "Please enter an amount in cents less than a dollar. \n";
  cin >> cents;
  
  quarters = cents/25;
  cents %= 25;
  dimes = cents/10;
  cents %=10;
  nickels = cents/5;
  cents %=5;
  pennies = cents;
  
  cout << "Your change will be: \n";
  cout << "Q: " << quarters << endl;
  cout << "D: " << dimes << endl;
  cout << "N: " << nickels << endl;
  cout << "P: " << pennies << endl;
  
  return 0;
}
