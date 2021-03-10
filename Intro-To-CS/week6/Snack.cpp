//Snack.cpp

/************************************************************
** Author: Christopher Rico
** Date:5/9/17
** Description: Week 6 assignment. Implementation file for snack class.
 Takes a string (snack name), a double (snack price), and an integer (# calories)
 as opening arguments. 
 Contains three get member functions: getName, getPrice, and getNumCalories.
*************************************************************/

#include "Snack.hpp"

//user-defined parameter constructor
Snack::Snack(std::string name, double price, int calories)
{
	snackName = name;
	snackPrice = price;
	snackCal = calories;
}

//getters - the names make it pretty obvious what they do!

//returns name of snack
std::string Snack::getName()
{
	return snackName;
}

//returns price of snack
double Snack::getPrice()
{
	return snackPrice;
}

//returns number of calories in snack
int Snack::getNumCalories()
{
	return snackCal;
}
