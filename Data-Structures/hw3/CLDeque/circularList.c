#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	list->sentinel = malloc(sizeof(struct Link));
	assert(list->sentinel != 0);

	list->sentinel->next = list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	struct Link *newLink = (struct Link *) malloc(sizeof(struct Link));
	assert(newLink != 0);

	newLink->value = value;
	newLink->next = NULL;
	newLink->prev = NULL;

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	struct Link *newLink = createLink(value);
	//point new link's next and prev at correct place
	newLink->next = link->prev;
	newLink->prev = link->next->prev;

	//point links on either side to new link
	link->next = link->next->prev = newLink;

	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
   struct Link *toDelete = link;

	 toDelete->prev->next = toDelete->next;
	 toDelete->next->prev = toDelete->prev;

	 free(toDelete);
	 list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	while(!circularListIsEmpty(list))
	{
		circularListRemoveFront(list);
	}

	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	struct Link *newLink = createLink(value);
	//point new link's next and prev at correct place
	newLink->next = list->sentinel->next;
	newLink->prev = list->sentinel;

	//point links on either side to new link
	list->sentinel->next = list->sentinel->next->prev = newLink;

	list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	struct Link *newLink = createLink(value);
	//point new link's next and prev at correct place
	newLink->prev = list->sentinel->prev;
	newLink->next = list->sentinel;

	//point links on either side to new link
	list->sentinel->prev = list->sentinel->prev->next = newLink;

	list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	assert(!circularListIsEmpty(list));
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	assert(!circularListIsEmpty(list));
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	return (list->size == 0);
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	struct Link *toPrint = list->sentinel->next;

	while(toPrint != list->sentinel)
	{
		printf("%f\n", toPrint->value);
		toPrint = toPrint->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	struct Link *toReverse = list->sentinel;
	struct Link *holdMe;

	do
	{
		holdMe = toReverse->next;
		toReverse->next = toReverse->prev;
		toReverse->prev = holdMe;

		toReverse = holdMe;
	} while (toReverse != list->sentinel);
}
