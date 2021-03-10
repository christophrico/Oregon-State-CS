/************************************************************************************
** Author: Christopher Rico
** Date: 4/12/17
** Description: Week 2 assignment. Program that converts Celsius temp to Farenheit temp
***********************************************************************************/

#include <iostream>
using namespace std;

int main ()
{
  double farenheit, //calculated value
         celsius; //user-input value
         
  cout << "Please enter a Celsius temperature. \n";
  cin >> celsius;
  
  farenheit = ((9*celsius)/5)+32;  //conversion formula for c to f
  
  cout << "The equivalent Farenheit temperature is: \n" << farenheit << endl;
  
  return 0;
}
