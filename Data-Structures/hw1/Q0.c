/* CS261- Assignment 1 - Q. 0*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that prints the value and address of a variable x
 both inside and outside of a function foo.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr)
{
     /*Print the value pointed to by iptr*/
     printf(" The value of x in fooA is %i\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf(" The address of x in fooA is %i\n", &*iptr);
     /*Print the address of iptr itself*/
     printf(" The address of iptr in fooA is %i\n\n", &iptr);
}

int main()
{

    /*declare an integer x*/
    int x = 7;

    /*print the address of x*/
    printf(" The address of x is %i\n\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x is %i\n", x);

    return 0;
}
