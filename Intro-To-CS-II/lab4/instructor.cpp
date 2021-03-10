/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Implementation file for instructor class. This class is derived from the
             person class.
             Contains get/set methods for instructor info:
             -name
             -age
             -rating
             Also contains doWork method that prints to screen how many hours the
             instructor graded papers for (randomly generated between  0 and 60 )
             Compile with person.cpp, university.cpp, inputVal.cpp, main.cpp

*/

#include "instructor.hpp"

//Instructor constructor (lol) allows user to set name when object is created
//generates age between 25 and 90, score between 0.0 and 5.0
Instructor::Instructor(string n) : Person()
{
    name = n;

    age = randIntRange(25,90);

    score = randDoubRange(0.0,5.0);
}

//returns "Instructor" + name
string Instructor::getName()
{
    ostringstream nameString;

    nameString << "Instructor " << name;

    return nameString.str();
}

//returns age
int Instructor::getAge()
{
  return age;
}

//returns "Rating: " + score as a string
//https://stackoverflow.com/questions/15385378/how-can-i-concatenate-float-with-string
string Instructor::getScore()
{
    ostringstream ratingString;

    ratingString << "Rating: " << fixed << setprecision(1) << score;

    return ratingString.str();

}

//generates random integer between 1 and 60,
// then prints "Instructor ____ graded papers for __ hours"
void Instructor::doWork()
{
    cout << endl << "Instructor " << name << " graded papers for "
         << randIntRange(0,60) << " hours." << endl;
}

//allows user to set name
void Instructor::setName(string n)
{
    name = n;
}

//allows user to set age
void Instructor::setAge(int a)
{
  age = a;
}

//allows user to set instructor ratingString
void Instructor::setScore(int sc)
{
  score = sc;
}
