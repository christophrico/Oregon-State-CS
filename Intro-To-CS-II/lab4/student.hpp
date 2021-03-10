/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Header file for student class
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "person.hpp"

class Student : public Person
{
private:
    string name;
    int age;
    double score;

public:
    Student(string);

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

#endif //STUDENT H
