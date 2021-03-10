/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/24/17
Assignment:	 CS 162 - Project 2
Description: Implementation file for item class. Allows for an 'item' to be
             created, with get/set methods for item info:
             -Name
             -Unit (pounds, ounces, box, can)
             -Unit price
             -quantity
             Also has a print method to print item info, and an overloaded ==
             to allow for comparing a search string to an item name.
             Compile with list.cpp, main.cpp, inputVal.cpp
*/

#include "item.hpp"


//default constructor, sets up an empty item
Item::Item()
{
    setName("null");
    setUnit(0);
    setQty(0);
    setUnitPrice(0.00);
}

//getters:

//returns item name
string Item::getName()
{
   return name;
}

//returns string version of unit
string Item::getUnit()
{
    //return the string for each unit
    switch(itemUnit)
    {
        case 0: return "null";
            break;
        case 1: return "Cans";
            break;
        case 2: return "Boxes";
            break;
        case 3: return "Pounds";
            break;
        case 4: return "Ounces";
            break;
    }

}

//returns item quantity
int Item::getQty()
{
    return qty;
}

//returns item price
double Item::getUnitPrice()
{
    return unitPrice;
}


//returns item extended price (quantity * item price)
double Item::getExtPrice()
{
    return (qty * unitPrice);
}

//prints item info to screen
void Item::printItem()
{
  cout << endl << " Name: " << name;
  cout << endl << " Unit: " << getUnit();
  cout << endl << " Qty: " << qty;
  cout << endl << " Unit price: $" << fixed << setprecision(2) << unitPrice;
  cout << endl << " Extd price: $" << fixed << setprecision(2) << getExtPrice();
  cout << endl;
}

//setters

//sets item name
void Item::setName(string n)
{
    name = n;
}

//sets item unit
void Item::setUnit(int u)
{
    itemUnit = u;
}

//sets item quantity
void Item::setQty(int q)
{
    qty = q;
}

//sets item price
void Item::setUnitPrice(double uP)
{
    unitPrice = uP;
}

//overloads == to compare item name with a string input
//returns true if they match, false if no match
bool Item::operator==(string b)
{
  return name == b;
}
