/* CS261- Assignment 1 - Q.4*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that allocates space for n students,
 												assigns them ids and scores, then sorts them based on
												their ids and scores
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student
{
	int id;
	int score;
};

void sort(struct student* students, int n)
{
     /*Sort the n students based on their score*/
   int holdMe;

    for (int i = 0; i < (n-1); i++)
    {
     for(int k = 0; k < (n-i-1); k++)
       {
         if(students[i].score > students[i+1].score)
         {
           holdMe = students[i].score;
           students[i].score = students[i+1].score;
           students[i+1].score = holdMe;

					 holdMe = students[i].id;
					 students[i].id = students[i+1].id;
					 students[i+1].id = holdMe;
         }
       }
     }
}

int main()
{
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student* classroom = malloc(sizeof(struct student) * n);

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    srand(time(NULL));

    int tmp;

		/* assign student IDs */
    for (int i = n - 1; i > 0; i--)
    {
        classroom[i].id = (rand()%9);
        tmp = classroom[i].id;
        classroom[i+1].id = classroom[i].id;
        classroom[i].id = tmp;
    }

		/*assign student scores*/
    for (int h = 0; h < n; h++)
    {
        classroom[h].score = (rand()%100);
    }


    /*Print the contents of the array of n students.*/
    printf("The contents of the unshuffled array are: \n");

    for (int j = 0; j < n; j++)
    {
      printf("Student %i: score of %i\n", classroom[j].id, classroom[j].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(classroom, n);

    /*Print the contents of the array of n students.*/
    printf("\n\nThe contents of the shuffled array are: \n");

    for (int p = 0; p < n; p++)
    {
      printf("Student %i: score of %i\n", classroom[p].id, classroom[p].score);
    }


    	free(classroom);

    return 0;
}
