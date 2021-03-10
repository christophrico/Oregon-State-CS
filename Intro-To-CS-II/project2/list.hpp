/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/24/17
Assignment:	 CS 162 - Project 2
Description: Header file for list class. 
*/

#ifndef LIST_H
#define LIST_H

#include "menu.hpp"
#include "item.hpp"


class List
{
private:
    int itemIdx;
    Item *itemArr, *tempArray;


    int searchItems(string);
    void updateItemInfo(int);

public:
    List();
    ~List();
    void addItem();
    void removeItem();
    void display();

};

#endif // LIST H
