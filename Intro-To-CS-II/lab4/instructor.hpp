/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Header file for Instructor class. Instructor is derived from Person
*/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "person.hpp"

class Instructor : public Person
{
private:
    string name;
    int age;
    double score;

public:
    Instructor(string);

    //getters
    virtual string getName();
    virtual int getAge();
    virtual string getScore();
    virtual void doWork();

    //setters
    void setName(string);
    void setAge(int);
    void setScore(int);
};

#endif //INSTRUCTOR H
