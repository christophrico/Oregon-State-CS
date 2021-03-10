/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
Description: Implementation file for building class.
            Stores information about builidings at a university.
            Contains get/set methods for:
            -Name
            -address
            -size (in square feet)
            Compile with university.cpp, main.cpp
*/

#include "building.hpp"

//constructor for user input of name, address, and size
Building::Building(string na, string ad, int si)
{
    name = na;
    address = ad;
    size = si;
}

//returns building name
string Building::getName()
{
    return name;
}

//returns building address
string Building::getAddress()
{
    return address;
}

//returns building size
double Building::getSize()
{
    return size;
}

//sets building name
void Building::setName(string n)
{
    name = n;
}

//sets building address
void Building::setAddress(string a)
{
    address = a;
}

//sets building size
void Building::setSize(double s)
{
    size = s;
}
