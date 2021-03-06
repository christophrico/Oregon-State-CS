/*
Name:		     Christopher Rico
OSU ID:	     933239746
Date:		     8/6/17
Assignment:	 CS 162 - Lab 6
Description: Queue class. Holds a QueueNode struct item that can be used to create
             a circular linked list
              Contains fucntions to:
             - add a node
             - remove the front node
             - display the front node
             - display the entire list of nodes

             compile with inputVal.cpp, main.cpp, menu.cpp

*/

#include "queue.hpp"

//constructor, sets QueueNode pointers to nullptr
Queue::Queue()
{
    back = front = nullptr;
}


//destructor, deletes queue nodes
Queue::~Queue()
{
    while (front != nullptr)
    {
        removeFront();
    }
}


/*****************************************************************************
 ** Description: prompts user to enter an integer to be stored in a node.
                 Creates a node, then puts it on the back of the list.
                 Points back pointer at it.
 ****************************************************************************/
void Queue::addBack()
{
    int newVal;
    QueueNode *addNode;

    //get integer from user and validate
    cout << endl << "Enter an integer to add to the queue: ";
    newVal = isInt();

    //if there are no values
    if (front == nullptr)
    {
      //create new node with correct value, point it at itself
      addNode = new QueueNode(newVal, addNode, addNode);
      //assign front and back to it
      front = addNode;
      back = addNode;
    }

    //otherwise
    else
    {
      //create a new node with the correct value
      addNode = new QueueNode(newVal, front, back);

      //point previous last node at it
      back->next = addNode;
      //and front node at it
      front->prev = addNode;
      //reassign back to the new node
      back = addNode;
    }

    cout << endl << newVal << " successfully added.";

    addNode = nullptr;
}


/*****************************************************************************
 ** Description: Retrieves value of front node, and prints it to the screen
                 If there is no front node, says so.
 ****************************************************************************/
void Queue::printFront()
{
    //if there's nothing in the queue, say so
    if (front == nullptr)
        cout << endl << "The queue is empty.";

    else
        cout << endl << "The first value in the queue is " << getFront();

}


/*****************************************************************************
 ** Description: Removes the front node from the linked list. If there are no
                  front nodes in the list, says so.
 ****************************************************************************/
void Queue::removeFront()
{
    QueueNode *temp;

    //if the queue is empty, say so
    if (front == nullptr)
        cout << endl << "The queue is empty.";

    //if only one value, just delete it and set it to nullptr
    else if (front == back)
    {
      delete front;
      front = nullptr;
      back = nullptr;

      cout << endl << "Successfully deleted.";
    }

    //if more than one value
    else
    {
        //save the memory location of the node to be deleted
        temp = front;
        //point front at the new front, back at the new front
        front = front->next;
        back->next = front;
        //free the memory that temp points at and set it to nullptr
        delete temp;

        cout << endl << "Successfully deleted.";
    }

    temp = nullptr;
}


/*****************************************************************************
 ** Description: Prints all the values in the list. If the list is empty, say so.
 ****************************************************************************/
void Queue::printQueue()
{
    QueueNode *current;

    //check to see that list is not empty
    if (front == nullptr)
        cout << endl << "The queue is empty";

    //if only one value, just print it
    else if (front == back)
      cout << endl << front->value;

    //if it has values, print them to screen until looping back around to front
    else
    {
        current = front;
        cout << endl;

        do
        {
            cout << current->value << "  ";
            current = current->next;

        } while(current != front);

    }

    current = nullptr;
}


/*****************************************************************************
 ** Description: Gets the value of the front node and returns it.
 ****************************************************************************/
int Queue::getFront()
{
      if (front != nullptr)
        return front->value;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
