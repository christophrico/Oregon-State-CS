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

using namespace std;

#define SIZE 32768
float Array[2*SIZE];
float Sums[1*SIZE];


//autocorrelation function that will use openMP to make the operation threaded
//on the specified number of threads
//then write out results to specified dataFile
void autoCorrelate(float *arr, float *sums, int size, int threads, string dataFile)
{
  FILE *fd = fopen(dataFile.c_str(), "w");

  omp_set_num_threads(threads);

  int timesToLoop = 10;
  double averageTime = 0;
  double peakTime = 1000;

  //use this loop to take the average time of several runs
  for(int loop = 0; loop < timesToLoop; loop++)
  {
    double tStart = omp_get_wtime();

    #pragma omp parallel for default(none) shared(size, arr, sums)
    for(int shift = 0; shift < size; shift++)
    {
      float sum = 0.0;
      for(int i = 0; i < size; i++)
      {
        sum += arr[i] * arr[i+shift];
      }
      sums[shift] = sum;
    }

    //get the time for this run
    double tEnd = omp_get_wtime();
    if(tEnd - tStart < peakTime)
      peakTime = tEnd - tStart;
  }
  //calculate the average time
  averageTime /= timesToLoop;


  //write the performance results to file
  fprintf(fd, "Threads,Peak Performance (MegaLoops/s),Ave Performance (MegaLoops/s)\n");
  fprintf(fd, "%d,%lf,%lf\n", threads, (double)size*size / peakTime / 1000000, (double)size*size / peakTime / 1000000);

  //print the autocorrelated sums to the file
  fprintf(fd, "Index,Sum\n");
  for(int i = 0; i < size; i++)
    fprintf(fd, "%d,%f\n", i, sums[i]);

  fclose(fd);

  return;
}


int main()
{
  #ifndef _OPENMP
    std::fprintf(stderr, "OpenMP not supported, exiting program.\n");
    return 1;
  #endif


  FILE *fd = fopen("signal.txt", "r");

  if(!fd)
    cout << "Could not open file" << endl;

  int size;
  fscanf(fd, "%d", &size);
  size = SIZE;


  for (int i = 0; i < size; i++)
  {
    fscanf(fd, "%f", &Array[i]);
    Array[i+size] = Array[i];
  }

  fclose(fd);

  //run the autocorrelation with 1 thread
  autoCorrelate(Array, Sums, size, 1, "ompResults1.csv");
  //run the autocorrelation with 16 threads
  autoCorrelate(Array, Sums, size, 16, "ompResults2.csv");

  return 0;
}
