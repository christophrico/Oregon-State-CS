/*
Name:		     Christopher Rico
OSU ID:	     933239746
Date:		     8/6/17
Assignment:	 CS 162 - lab 6
Description:

*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "inputVal.hpp"


class Queue
{
    private:
        //node data type
        struct QueueNode
        {
            int value;
            QueueNode *next, *prev;

            //Queuenode constructor, sets node value and points to next/prev nodes
            QueueNode(int value1, QueueNode *next1, QueueNode *prev1)
            {
                value = value1;
                next = next1;
                prev = prev1;
            }

        };

        QueueNode *front, *back;
        int getFront();

    public:
        //constructor and destructor
        Queue();
        ~Queue();

        //list operation functions
        void addBack();
        void printFront();
        void removeFront();
        void printQueue();
};

#endif // QUEUE HPP
