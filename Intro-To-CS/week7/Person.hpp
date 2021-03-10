//Person.hpp

 /************************************************************
** Author: Christopher Rico
** Date:5/17/17
** Description: Week 7 assignment. Header file for "Person" class
*************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
	std::string name;
	double age;

public:
	//constructor for user input
	Person(std::string , double);

	//getters
	std::string getName();
	double getAge();
}; 

#endif // PERSON H 
