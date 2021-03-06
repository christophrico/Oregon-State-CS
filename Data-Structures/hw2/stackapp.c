/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	DynArr *charStack = newDynArr(2);
	char current;

	do
	{
		current = nextChar(s);

		/* test for opening brackets, add to stack if any found */
		if ( current == '(' )
		{
			addDynArr(charStack, ')');
		}

		else if (current == '{')
		{
			addDynArr(charStack, '}');
		}

		else if (current == '[')
		{
			addDynArr(charStack, ']');
		}

		/* test for closing }. If opening { is not there, return false  */
		else if (current == '}')
		{
			if(sizeDynArr(charStack) == 0)
			{
				deleteDynArr(charStack);
				return 0;
			}

			else if(topDynArr(charStack) == '}')
			{
				popDynArr(charStack);
			}

			else
			{
				deleteDynArr(charStack);
			}
		}

		/* test for closing ). If opening { is not there, return false  */
		else if(current == ')')
		{
			if(sizeDynArr(charStack) == 0)
			{
				deleteDynArr(charStack);
				return 0;
			}

			else if(topDynArr(charStack) == ']')
			{
				popDynArr(charStack);
			}

			else
			{
				deleteDynArr(charStack);
			}
		}

		/* test for closing ]. If opening { is not there, return false  */
		else if (current == ']')
		{
			if(sizeDynArr(charStack) == 0)
			{
				deleteDynArr(charStack);
				return 0;
			}

			else if(topDynArr(charStack) == ']')
			{
				popDynArr(charStack);
			}

			else{
				deleteDynArr(charStack);
			}
		}

	} while(current != '\0');


	if (sizeDynArr(charStack) == 0 )
	{
		deleteDynArr(charStack);
		return 1;
	}

	else
	{
		deleteDynArr(charStack);
		return 0;
	}
}



int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}
