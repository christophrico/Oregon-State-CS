/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Implementation file for university class.
              Contains 3 public methods:
              - printBldgs, displays building information
              -printPpl, displays person information
              -chooseWork, displays people and asks user to choose one person to
               'do work', then calls doWork method on selected person
               Compile with person.cpp instructor.cpp student.cpp main.cpp inputVal.cpp
*/

#include "university.hpp"

//constructor: instantiates several buildings, students, and instructors
University::University()
{
    //create students
    people.push_back(new Student("Harry Potter"));
    people.push_back(new Student("Hermione Granger"));
    people.push_back(new Student("Ron Weasley"));
    people.push_back(new Student("Neville Longbottom"));
    //create instructors
    people.push_back(new Instructor("Minerva McGonogall"));
    people.push_back(new Instructor("Severus Snape"));
    people.push_back(new Instructor("Filius Flitwick"));


    //create buildings, push into vector
    Building greenhouse("East Greenhouse",
                  "2801 SW CAMPUS WAY CORVALLIS, OR 97331", 31247);
    Building langton("Langton Hall",
                  "2450 SW JEFFERSON WAY CORVALLIS, OR 97331", 95037);
    Building lab("Rosenfeld Laboratory",
                  "5501 NW WALNUT BLVD CORVALLIS, OR 97330",13512);

    buildings.push_back(greenhouse);
    buildings.push_back(langton);
    buildings.push_back(lab);
}

//destructor: deallocates dynamic student/instructor objects and clears people vector
University::~University()
{
  for (int i = 0; i < people.size(); i++)
  {
    delete people[i];
  }

  people.clear();
}

//prints a list of university buildings
void University::printBldgs()
{
    //print header
    cout << endl << "OSU Buildings";
    cout << endl << "-------------";

    //print the details for each building
    for (int i = 0; i < buildings.size(); i++)
    {
        cout << endl << buildings[i].getName();
        cout << endl << buildings[i].getAddress();
        cout << endl << buildings[i].getSize() << " sq ft";
        cout << endl;
    }
}

//prints a list of university people
void University::printPpl()
{
    //print header
    cout << endl << "People at OSU";
    cout << endl << "-------------";

    //print details for each person
  for (int i = 0; i < people.size(); i++)
    {
        cout << endl << (i+1) << ". " << people[i]->getName();
        cout << endl << people[i]->getAge() << " years old";
        cout << endl << people[i]->getScore();
        cout << endl;
    }
}

//choose a person to do work
void University::chooseWork()
{
    int workChoice;

    cout << endl << "Select a person at OSU to do work.";
    cout << endl << "Enter the number of the person you would like to select. ";

    //print the people at OSU
    printPpl();

    workChoice = intRange(1, people.size());
    //have the user choose one of the people, valdate that person exists,
    //and make the person do work
    people[workChoice-1]->doWork();
}
