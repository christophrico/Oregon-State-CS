/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: This program takes three numbers and sorts
* their values into ascending order.
************************************************************/

#include <iostream>
using namespace std;

void smallSort(int *one, int *two, int *three) //returns nothing, three pointer variables
{                                            //for arguments
	int holdMe;

	if(*one > *two)     //if first number is greater than second
	{                 //flip them
	  holdMe = *one;
	  *one = *two;
	  *two = holdMe;
	}
	if(*one > *three)  //if first number is greater than third
	{                //flip them
	  holdMe = *one;
	  *one = *three;
	  *three = holdMe;
	}
	if(*two > *three)  //if second number is greater than third
	{                //flip them
	  holdMe = *two;
	   *two = *three;
	   *three = holdMe;
	}
}

/*
int main()
{
  int a,b,c;

	cout << "Please enter three integers:" << endl;
	cin >> a >> b >> c;
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

	smallSort(&a, &b, &c);

	cout << "After smallSort, a = " << a << ", b = " << b << ", c = " << c << endl;

  return 0;
}
*/
