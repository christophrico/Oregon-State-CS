/*
  Christopher Rico
  Project 3
  CS475
  OSU ID: 933239746
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <omp.h>

using namespace std;

#define ARRAYSIZE 4

struct s
{
  float value;
  int pad[NUMPAD];
} Array[ARRAYSIZE];

const int iterations = 10000000;


//FIX 1: we use padding, FIX 2: we use temp variable
//NUMT = number of threads
//NUMPAD = number of ints to pad the struct with
//argv[1] = name of file to append data to
int main(int argc, char * argv[])
{
  #ifndef _OPENMP
    fprintf(stderr, "OpenMP not supported on this device. Exiting program.\n");
    return 1;
  #endif

  FILE *datafile = fopen(argv[1], "a");

  omp_set_num_threads(NUMT);


  //variables for recording performance
  int ave_iters = 100;
  double average = 0;
  double peak = 0;

  for(int k = 0; k < ave_iters; k++)
  {
    double t_not = omp_get_wtime();

    //fix 1
    if(FIX == 1)
    {
      #pragma omp parallel for default(none) shared(Array)
      for( int i = 0; i < ARRAYSIZE; i++ )
      {
        for(unsigned int j = 0; j < iterations; j++)
        {
          Array[ i ].value = Array[ i ].value + 2.;
        }
      }
    }

    //fix 2
    else
    {
      #pragma omp parallel for default(none) shared(Array)
      for(int i = 0; i < ARRAYSIZE; i++)
      {
        float temp = Array[i].value;

        for(unsigned int j = 0; j < iterations; j++)
        {
          temp += 2;
        }
        Array[i].value = temp;
      }
    }

    //calculate peak and average
    if((double)ARRAYSIZE * (double)iterations / (omp_get_wtime() - t_not) > peak)
      peak = (double)ARRAYSIZE * (double)iterations / (omp_get_wtime() - t_not);

    average += (double)ARRAYSIZE * (double)iterations / (omp_get_wtime() - t_not);
  } // average loop


  //print out results
  fflush(stdout);
  fprintf(datafile, "%d,%d,%.2lf,%.2lf\n",NUMT, NUMPAD, peak/1000000., average/(1000000.*ave_iters));

  fclose(datafile);

  return 0;
}
