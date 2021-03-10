// Snack.hpp
 
 /************************************************************
** Author: Christopher Rico
** Date:5/9/17
** Description: Week 6 assignment. Header file for Snack class
*************************************************************/

#ifndef SNACK_H
#define SNACK_H

#include <string>

class Snack
{
private:
	std::string snackName;
	double snackPrice;
	int snackCal;

public:
	//default constructor
	Snack()
	{
		snackName = "bottled water";
		snackPrice = 1.75;
		snackCal = 0;
	}

	//constructor for user input
	Snack(std::string, double, int);

	//getters
	std::string getName();
	double getPrice();
	int getNumCalories();
};

#endif // SNACK H
