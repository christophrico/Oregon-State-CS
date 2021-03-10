/* CS261- Assignment 1 - Q.2*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that prints various numbers, passes some of them b
                        reference to a function foo, then does arithmetic on them
                        and then re-prints their values
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c)
{
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b /= 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main()
{
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("The value of x is %i\n", x);
    printf("The value of y is %i\n", y);
    printf("The value of z is %i\n\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
    printf("Calling foo.\n");
    printf("The value returned by foo is %i\n", foo(&x, &y, z));

    /*Print the values of x, y and z again*/
    printf("Now the value of x is %i\n", x);
    printf("Now the value of y is %i\n", y);
    printf("Now the value of z is %i\n\n", z);

    /*Is the return value different than the value of z?  Why?*/
    /*No, becuase z was not passed as a pointer. Its value in main was never changed.*/
    return 0;
}
