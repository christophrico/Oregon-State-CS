/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Header file for pack container class

*/

#ifndef PACK_HPP
#define PACK_HPP

#include "inputVal.hpp"

class Pack
{
private:
    //struct that makes up the items in the pack
    //doubly-linked item with a name variable
    struct Moop
    {
        string name;
        Moop *next, *prev;

        Moop(string n, Moop *next1, Moop *prev1)
        {
            name = n;
            next = next1;
            prev = prev1;
        }
    };

    Moop *front, *back;
    int numItems;

public:
    //constructor and destructor
    Pack();
    ~Pack();

    //to search through the pack
    bool searchItems(string);
    //to add an item to the pack
    void addItem(string);
    //to remove an item from the pack
    void removeItem();
    //to swap an item in the pack for an incoming item
    void tradeItem(string, string);
    //to print the items in the pack
    void printItems();
};

#endif // PACK HPP
