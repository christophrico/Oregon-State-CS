/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/24/17
Assignment:	 CS 162 - Project 2
Description: Header file for item class.
*/

#ifndef ITEM_H
#define ITEM_H

#include "inputVal.hpp"

class Item
{
private:
    string name;
    int itemUnit;
    int qty;
    double unitPrice;

public:
    Item();

    //getters
    string getName();
    string getUnit();
    int getQty();
    double getUnitPrice();
    double getExtPrice();
    void printItem();

    //setters
    void setName(string);
    void setUnit(int);
    void setQty(int);
    void setUnitPrice(double);

    //overloaded == operator 
    bool operator==(string b);

};

#endif // ITEM H
