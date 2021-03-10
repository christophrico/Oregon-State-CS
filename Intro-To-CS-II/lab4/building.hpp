/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Header file for buiilding class
*/

#ifndef BUILDING_H
#define BUILDING_H

#include "inputVal.hpp"
#include <vector>

class Building
{
private:
    string name, address;
    double size;

public:
    Building(string, string, int);

    //getters
    string getName();
    string getAddress();
    double getSize();

    //setters
    void setName(string);
    void setAddress(string);
    void setSize(double);

};

#endif // BUILDING H
