/* CS261- Assignment 1 - Q.3*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that allocates space for an array, fills it with
                        Random numbers, then sorts the array of numbers.
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void sort(int* number, int n)
{
    int holdMe;

     for (int i = 0; i < n-1; i++)
     {
      for (int k = 0; k < n - i - 1; k++)
      {
        if(number[i] > number[i+1])
        {
          holdMe = number[i];
          number[i] = number[i+1];
          number[i+1] = holdMe;
        }
      }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 15;

    /*Allocate memory for an array of n integers using malloc.*/
    int *arr = malloc (sizeof(int) * n);

    /*Fill this array with random numbers, using rand().*/
    srand(time(NULL));

    for( int i = 0; i < n; i++)
    {
      arr[i] = (rand()%100);
    }

    /*Print the contents of the array.*/
    printf("The contents of the unsorted array are: \n");

    for(int j = 0; j < n; j++)
    {
      printf("%i\n", arr[j]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr, n);

    /*Print the contents of the array.*/
    printf("The contents of the sorted array are: \n");

    for(int k = 0; k < n; k++)
    {
      printf("%i\n", arr[k]);
    }

    free (arr);
    return 0;
}
