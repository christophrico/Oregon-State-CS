/*
  Christopher Rico
  Project 7
  CS475
  OSU ID: 933239746
*/


#include <cstdlib>
#include <omp.h>
#include <iostream>
#include <string>
#include <cstdio>
#include "simd.h"

using namespace std;

#define SIZE 32768
float Array[2*SIZE];
float Sums[1*SIZE];


int main()
{

  #ifndef _OPENMP
      fprintf(stderr, "OpenMP not supported, exiting program.\n");
      return 1;
  #endif

  FILE *fd = std::fopen("signal.txt", "r");

  if(!fd)
    cout << "Failed to open file." << endl;

  int size;
  fscanf(fd, "%d", &size);
  size = SIZE;

  for(int i = 0; i < size; i++)
  {
    fscanf(fd, "%f", &Array[i]);
    Array[i+size] = Array[i];
  }


  int timesToLoop = 10;
  double averageTime = 0;
  double peakTime = 1000;


  //use this loop to take the average time of several runs
  for(int loop = 0; loop < timesToLoop; loop++)
  {
    double tStart = omp_get_wtime();

    for(int shift = 0; shift < size; shift++)
    {
      Sums [shift] = SimdMulSum(Array, &Array[shift], size);
    }

    //get the time for this run
    double tEnd = omp_get_wtime();
    if(tEnd - tStart < peakTime)
      peakTime = tEnd - tStart;
  }

  //calculate the average time
  averageTime /= timesToLoop;


  //open the output file
  fd = fopen("simdResults.csv", "w");
  //write the performance results to file
  fprintf(fd, "Peak Performance (MegaLoops/s),Ave Performance (MegaLoops/s)\n");
  fprintf(fd, "%lf,%lf\n", (double)size*size / peakTime / 1000000, (double)size*size / peakTime / 1000000);

  //print the autocorrelated sums to the file
  fprintf(fd, "Index,Sum\n");
  for(int i = 0; i < size; i++)
    fprintf(fd, "%d,%f\n", i, Sums[i]);

  fclose(fd);

  return 0;
}
