/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for Pack class. Creates a doubly-linked container
             For storing user's objects they collect through the game. Max of 3 objects.

             Compile with inputVal.cpp, player.cpp, space.cpp, deepplaya.cpp,
                          distrikt.cpp, man.cpp, rv.cpp, temple.cpp, nineoclock.cpp

*/

#include "pack.hpp"

// constructor, set front and back to null
Pack::Pack()
{
    back = front = nullptr;
    numItems = 0;
}

//delete the pack items
Pack::~Pack()
{
     Moop *temp;

    //if only one value, just delete it and set it to nullptr
  for(int i = 0; i < numItems; i++)
  {
      if (front == back)
      {
        delete front;
        front = nullptr;
        back = nullptr;
      }

      //if more than one value
      else if (front != nullptr)
      {
          //save the memory location of the node to be deleted
          temp = front;
          //point front at the new front, back at the new front
          front = front->next;
          back->next = front;
          //free the memory that temp points at and set it to nullptr
          delete temp;
    }
  }
}

//adds item to pack. Takes the name of the item to be added as parameter.
void Pack::addItem(string s)
{
    Moop* addThing;
    char deleteChoice;

    //if there are no items and item does not already exist
    if (front == nullptr && !searchItems(s))
    {
      //create new node with correct value, point it at itself
      addThing = new Moop(s, addThing, addThing);
      //assign front and back to it
      front = addThing;
      back = addThing;

      numItems++;
    }

    //if there are fewer than 3 items in the bag and the item doesn't exist, you can add another
    else if(numItems < 3 && !searchItems(s))
    {
      //create a new node with the correct value
      addThing = new Moop(s, front, back);

      //point previous last node at it
      back->next = addThing;
      //and front node at it
      front->prev = addThing;
      //reassign back to the new node
      back = addThing;

      numItems++;
    }

    //if there are more than 3 items, no more can come in
    else if(numItems >= 3 && !searchItems(s))
    {
        cout << endl << endl << "You have too many items in your pack!";
        cout << endl << "Would you like to remove an item to make space? Y/N: ";

        deleteChoice = isChar2('Y','N');

        if (deleteChoice == 'Y')
        {
            //tells user to choose an item to remove, then re-calls add item
            removeItem();
            addItem(s);
            cout << endl << s << " added to your pack!";
        }
    }

    //if the item already exists, user can't add it again.
    else if (searchItems(s))
    {
        cout << endl << "This item is already in your pack! You cannot add it again.";
    }


    addThing = nullptr;
}

//allows for user to choose an item to remove
void Pack::removeItem()
{
    Moop *temp;
    int deleteChoice;

    //print the items for the user
    cout << endl;
    printItems();
    cout << endl << endl << "Choose an item to ditch. Enter 1-3: ";

    //validate user input
    deleteChoice = intRange(1,3);

    //first item
    if( deleteChoice == 1)
    {
        //save the memory location of the node to be deleted
        temp = front;
        //point front at the new front, back at the new front
        front = front->next;
        back->next = front;

        //free the memory that temp points at and set it to nullptr
        delete temp;
    }

    //second item
    else if (deleteChoice == 2)
    {
        //save the memory location of the item to be deleted
        temp = front->next;
        //set front and back items to point at each other
        front->next = back;
        back->next = front;
        back->prev = front;

        delete temp;
    }

    //third item
    else if (deleteChoice == 3)
    {
        //save address of item to be deleted
        temp = back;
        //point second and first items at each other
        back = front->next;
        front->prev = back;
        back->prev = front;

        delete temp;
    }

    numItems--;
    temp = nullptr;
}

//prints numbered list of the itemss
void Pack::printItems()
{
    Moop *current;

    //check to see that list is not empty
    if (front == nullptr)
        cout << endl << "You don't have any items in your bag!";

    //if only one item, just print it
    else if (front == back)
        cout << endl << numItems << ". " << front->name ;

    //if it has multiple items, print them to screen
    else
    {
        current = front;
        cout << endl << "You have these items:" << endl;

        for(int i = 0; i < numItems; i++)
        {
            //print name and index
            cout << (i+1) << ". " << current->name << endl;
            //point current at the next item
            current = current->next;
        }
    }


    current = nullptr;
}

//swaps an item in the pack for an incoming item
void Pack::tradeItem(string in, string out)
{
    Moop* swap;

    swap = front;

    //if there is an item in the list
    if (swap != nullptr)
    {
        //if the first item matches the one to remove, replace it
        if(swap->name == out)
            swap->name = in;

        //if the second item matches the one to remove, replace it
        else if((swap->next)->name == out)
            (swap->next)->name = in;

        //if the third item matches the one to remove, replace it
        else if (back->name == out)
            back->name = in;
    }

    swap = nullptr;
}

//searches for an item in the list and returns true if there's a match
bool Pack::searchItems(string s)
{
    Moop* query = front;
    bool found = false;

    //only search if there are items
    if (query != nullptr)
    {
        //loop through each item
        for (int i = 0; i < numItems; i++)
        {
            //if the name matches the search string, set found to true
            if (query->name == s)
                found = true;

            query = query->next;
        }
    }

    //return whether item was found or not
    return found;
}
