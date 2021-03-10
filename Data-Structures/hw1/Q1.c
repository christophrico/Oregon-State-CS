/* CS261- Assignment 1 - Q.1*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that allocates space for, generates scores and IDs for,
 gives the min, max, and average of, and then deallocates space for a list of 10 students.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student
{
	int id;
	int score;
};


struct student* allocate()
{
     /*Allocate memory for ten students*/
		 struct student* room = malloc(sizeof(struct student) * 10);

     /*return the pointer*/
		 return room;
}

void generate(struct student* students)
{
		/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
		srand(time(NULL));

		/* assign ID */
		for (int k = 0; k < 10; k++)
		{
			students[k].id = k;
		}

		/*assign scores*/
		for (int j = 0; j < 10; j++)
		{
			students[j].score = (j * 9) + j + (j/2);
		}

	int holdMe;
	/*shuffle scores*/
		for(int i = 0; i < 10; i++)
		{
			if (i % 2 != 0)
			{
			 holdMe = students[i].score;
			 students[i].score = students[i+1].score;
			 students[i+1].score = holdMe;
			}
		}
}

void output(struct student* students)
{
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
		printf("\n\n Student information: \n");

		for(int i = 0; i < 10; i++)
				printf("ID %d Score %d\n", students[i].id, students[i].score);

}

void summary(struct student* students)
{
		int min = 0;
		int max = 0;
		int accum;
		double average;

     /*Compute and print the minimum, maximum and average scores of the ten students*/
		 for (int i = 0; i < 10; i++)
		 {
			 if (min > students[i].score)
			 		min = students[i].score;

			 if (max < students[i].score)
			 		max = students[i].score;

			 accum += students[i].score;
		 }

		 average = accum/10;

		 printf("\n\nThe minimum score is %i, and the maximum score is %i\n", min, max);
		 printf("The average score is %f \n\n", average);
}

void deallocate(struct student* students)
{
		 free(students);
}

int main()
{
    struct student* stud = NULL;

    /*call allocate*/
		stud = allocate();

    /*call generate*/
		generate(stud);

    /*call output*/
		output(stud);

    /*call summary*/
		summary(stud);

    /*call deallocate*/
		deallocate(stud);

    return 0;
}
