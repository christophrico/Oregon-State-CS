/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Implementation file for person class. This is a base class for
             student and instructor classes
             Contains get/set methods for person info:
             -name
             -age
             -rating
             Also contains doWork method that prints to screen "today I don't
             feel like doing anything"
             Compile with university.cpp, inputVal.cpp, main.cpp
*/

#include "person.hpp"

//sets person info to simple values
Person::Person()
{
    name = "noName";
    age = 18;
    score = 0;
}

//returns name
string Person::getName()
{
    return name;
}

//returns age
int Person::getAge()
{
    return age;
}

//returns 'score'
string Person::getScore()
{
    return to_string(score);
}

//prints silly phrase to screen
void Person::doWork()
{
    cout << "Today I don't feel like doing anything";
}

//returns name
void Person::setName(string n)
{
    name = n;
}

//returns age
void Person::setAge(int a)
{
  age = a;
}

//returns score
void Person::setScore(int sc)
{
  score = sc;
}
