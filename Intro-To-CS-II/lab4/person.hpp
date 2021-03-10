/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Header file for person class
*/

#ifndef PERSON_H
#define PERSON_H

#include "inputVal.hpp"

class Person
{
private:
    string name;
    int age;
    double score;

public:
    Person();

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

#endif //PERSON H
