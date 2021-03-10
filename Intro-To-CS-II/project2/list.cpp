/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/24/17
Assignment:	 CS 162 - Project 2
Description: Implementation file for list class. Creates and maintains a shopping
              list of item objects that can be added, edited or removed by user.
              Has 3 public member funtions:
              - addItem: Prompts user to search an item name in the list. If
                         item exists, asks user if they would like to update it.
                         If item does not exist, allows user to create item and
                         fill in its information.
              - removeItem: Prompts user to search for an item name in list.
                            If item exists, user may remove item from the list.
              - display: Displays items in list and calculates total cost of items
                         based on quantity and item prices.
              Compile with main.cpp, inputVal.cpp, menu.cpp, and item.cpp
*/

#include "list.hpp"

//constructor, sets both arrays to nullptr
List::List()
{
    itemIdx = -1;
    itemArr = tempArray = nullptr;
}

//destructor, deletes both arrays from any data they may hold
List::~List()
{
  delete []itemArr;
  delete []tempArray;
}

//allows user to add a new item or update an existing one
void List::addItem()
{
    string searchName;
    int addIdx;

    //ask user for item to search for, then search for it
    cout << endl << "Please enter an item name: " << endl;
    getline(cin, searchName);
    addIdx = searchItems(searchName);

    //if item exists, ask user if they would like to update it
    if (addIdx >= 0)
    {
        cout << endl << "This item is already on your list.";
        cout << endl << "Would you like to update the information for "
             <<  itemArr[addIdx].getName() << "? y/n " << endl;

        //if yes, update item info
        if (isChar2('y','n') == 'y')
        {
            updateItemInfo(addIdx);
        }
    }

    //if item does not exist, ask if user wants to create one
    else if (addIdx < 0)
    {
        cout << endl << "Would you like to create a new item? y/n. ";
        if (isChar2('y','n') == 'y')
        {
          itemIdx++;

          //define new item array with one more object
          tempArray = new Item[(itemIdx+1)];

          //copy old items into new array
          for (int i = 0; i < itemIdx; i++)
          {
              tempArray[i] = itemArr[i];
          }

          //remove old array pointer from original array and point at new array
          delete []itemArr;
          itemArr = tempArray;
          tempArray = nullptr;

          //set item name, then ask user to fill out other info
          itemArr[itemIdx].setName(searchName);
          cout << endl << " Item created! Let's add some details.";
          updateItemInfo(itemIdx);
        }
    }
}

//removes item from array, shifts others a position to fill empty spot
void List::removeItem()
{
    string searchName;
    int delIdx;

    //ask user which item they would like to delete, then search for it
    cout << endl << "Please enter an item name: " << endl;
    getline(cin, searchName);
    delIdx = searchItems(searchName);

    //if item exists
    if (delIdx >= 0)
    {
        cout << endl << "Are you sure you want to delete this item? y/n. ";

        //if user wants to delete item
        //delete item, move all other items up in array
        if (isChar2('y','n') == 'y')
        {
            //make new array with one less item
            tempArray = new Item[(itemIdx)];

            //copy old items into new array, except the item to be deleted
            for (int i = 0; i < delIdx; i++)
            {
                //items before item to delete copied in at same position
                tempArray[i] = itemArr[i];
            }

            for (int k = delIdx+1; k<=itemIdx; k++)
            {
                //items after deleted item copied in at one position lower
                tempArray[k-1] = itemArr[k];
            }

            itemIdx--;

            //remove old array pointer from original array and point at new array
            delete []itemArr;
            itemArr = tempArray;
            tempArray = nullptr;
        }
    }

    //if item DNE, display message and return to menu
    else if (delIdx < 0)
    {
      cout << endl << searchName << " is not an item in your list." << endl;
    }
}

//prints list to screen, calculates total item price
void List::display()
{
    double grandTotal = 0;

    //if cart is empty, say so
    if (itemIdx < 0)
    {
        cout << endl << "Your list is empty! Select 2 to add an item. " << endl;
    }

    //if cart has items, display them
    else
    {
        //print header
        cout << endl << endl << setw(2) << " -- Shopping List -- ";

        //print individual items and data, sum up grand total price
        for (int i = 0; i <= itemIdx; i++)
        {
            itemArr[i].printItem();
            cout << endl;

            grandTotal += itemArr[i].getExtPrice();
        }

        //print total price for all items
        cout << "______________________";
        cout << endl << "Grand Total: $" << fixed
                     << setprecision(2) << grandTotal << endl << endl;
    }
}

//searches items based on name, returns arr index of item. If item DNE, returns -1
int List::searchItems(string searchString)
{
    int position = -1,
        i = 0;
    bool found = false;

    //loop through items comparing title to search string
    while (i <= itemIdx && !found)
    {
      //when found, record the position it's found at
      if (itemArr[i] == searchString)
      {
        position = i;
        found = true;
      }
      i++;
    }

    //return the index, or return -1 for nothing found
    return position;
}

//steps through item attributes and updates each one if user indicates
void List::updateItemInfo(int updIndex)
{
    string tempName;
    int changeChoice;

    //display item info
    itemArr[updIndex].printItem();
    cout << endl;

    //give user choice of which item attributes to edit
    do
    {
        changeChoice = displayMenu2();

        //change the name
       if (changeChoice == 1)
       {
           cout << endl << "  Please enter a new item name." << endl << " ";
           getline(cin, tempName);
           itemArr[updIndex].setName(tempName);
       }

       //change the unit
       else if (changeChoice == 2)
       {
           cout << endl << "  Please choose an unit type:" << endl;
           cout << "  1. Can" << endl << "  2. Box" << endl
                << "  3. Pound" << endl << "  4. Ounce" << endl << " ";
            //set the unit, validate that it's 1-4
            itemArr[updIndex].setUnit(intRange(1, 4));
       }

        //change the quantity
        else if (changeChoice == 3)
        {
            cout << endl << " Please enter a quantity:" << endl << " ";
            //set the quantity, validate that qty is an integer
            itemArr[updIndex].setQty(isInt());
        }

        //change the price
        else if (changeChoice == 4)
        {
            cout << endl << " Please enter a unit price:" << endl << " ";
            //set the price, validate that price is a double
            itemArr[updIndex].setUnitPrice(isDouble());
        }

        //print the item info
        else if (changeChoice == 5)
        {
          cout << endl;
          itemArr[updIndex].printItem();
        }
    } while (changeChoice != 6);
}
