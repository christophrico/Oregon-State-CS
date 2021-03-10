//Person.cpp

/************************************************************
** Author: Christopher Rico
** Date:5/17/17
** Description: Week 7 assignment. Implementation file for "Person" class
  Default constructor takes two arguments, a string and a double.
  Has two member functions: getAge and getName.
*************************************************************/

  #include "Person.hpp"

  //default constructor for user input.
 Person::Person(std::string nameIn, double ageIn)
  {
  	name = nameIn;
  	age = ageIn;
  }

  //returns a string of the person name
 std::string Person::getName()
  {
  	return name;
  }

  //returns a double of the user age
 double Person:: getAge()
  {
  	return age;
  }
