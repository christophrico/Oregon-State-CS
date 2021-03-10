/************************************************************************************
** Author: Christopher Rico
** Date: 4/5/17
** Description: Week 1 assignment. Script that prints name of my favorite animal.
***********************************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;
             
	return 0;
}

