/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Implementation file for student class. This class is derived from the
             person class.
             Contains get/set methods for student info:
             -name
             -age
             -GPA
             Also contains doWork method that prints to screen how many hours the
             student did homework(randomly generated between  0 and 30)
             Compile with person.cpp, university.cpp, inputVal.cpp, main.cpp
*/

#include "student.hpp"

//allows for user to set name upon instantiation.
//also generates random age between 16 and 30, and random GPA between 0.0 and 4.0
Student::Student(string n) : Person()
{
    name = n;
    age = randIntRange(16,30);
    score = randDoubRange(0.0,4.0);
}

//returns name
string Student::getName()
{
  return name;
}

//returns age
int Student::getAge()
{
  return age;
}

//returns "GPA: "score as a string
//https://stackoverflow.com/questions/15385378/how-can-i-concatenate-float-with-string
string Student::getScore()
{
    ostringstream gpaString;

    gpaString << "GPA: " << fixed << setprecision(1) << score;

    return gpaString.str();
}

//prints "___ did (0-30) hours of homework."
void Student::doWork()
{
    cout << endl << name << " did " << randIntRange(0,30)
         << " hours of homework." << endl;
}

//sets name
void Student::setName(string n)
{
    name = n;
}

//sets age
void Student::setAge(int a)
{
  age = a;
}

//sets GPA
void Student::setScore(int sc)
{
  score = sc;
}
