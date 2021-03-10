/*
  Christopher Rico
  Project 5
  CS475
  OSU ID: 933239746
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include "simd.p5.h"


using namespace std;

float A[ARRSIZE];
float B[ARRSIZE];
float C[ARRSIZE];


float randFloat(unsigned int *seed, float low, float high);
void fillArray(float * array, int size);

//c++ multiplication
void mul(float *A, float *B, float *C, int len);
//c++ multiplication + reduction
float mulSum(float *A, float *B, int len);



int main(int argc, char *argv[])
{
  #ifndef _OPENMP
      fprintf(stderr, "OpenMP not supported on this machine. Exiting now.\n");
      return 1;
  #endif


  //open data files
  FILE *datafile = fopen(argv[1], "a");
  FILE *speedupData = fopen(argv[2], "a");

  fillArray(A, ARRSIZE);
  fillArray(B, ARRSIZE);


  float cppTime = 0;
  float cppPeak = 1000000;
  float sseTime = 0;
  float ssePeak = 1000000;

  int aveLoops = 200;

  double t0;
  double t;


  // if we are testing SIMD SSE Mult vs C++ Mult
  if (TEST == 0)
  {
    //C++ multiplication trials
    for(int i = 0; i < aveLoops; i++)
    {
      t0 = omp_get_wtime();
      mul(A, B, C, ARRSIZE);
      t = omp_get_wtime();

      cppTime += (t - t0);
      if(t - t0 < cppPeak)
        cppPeak = t- t0;
    }
    cppTime /= aveLoops;

    //SIMD multiplication trials
    for(int i = 0; i < aveLoops; i++)
    {
      t0 = omp_get_wtime();
      SimdMul(A, B, C, ARRSIZE);
      t = omp_get_wtime();

      sseTime += (t - t0);
      if(t - t0 < ssePeak)
        ssePeak = t - t0;
    }
    sseTime /= aveLoops;
  }


  //if we are testing SIMD SSE vs C++ Mult + Reduction
  else
  {
    //C++ multiplication + Reduction trials
    for(int i = 0; i < aveLoops; i++)
    {
      t0 = omp_get_wtime();
      float sum = mulSum(A, B, ARRSIZE);
      t = omp_get_wtime();

      cppTime += (t - t0);
      if(t - t0 < cppPeak)
        cppPeak = t- t0;
    }
    cppTime /= aveLoops;

    //SIMD multiplication + reduction trials
    for(int i = 0; i < aveLoops; i++)
    {
      t0 = omp_get_wtime();
      float sum = SimdMulSum(A, B, ARRSIZE);
      t = omp_get_wtime();

      sseTime += (t - t0);
      if(t - t0 < ssePeak)
        ssePeak = t - t0;
    }
    sseTime /= aveLoops;
  }


  //outputs results to files
  fprintf(datafile, "Normal C++ Data:\n"
          "Array Size,Peak Speed,Average Speed\n"
          "%d,%.8f,%.8f\n", ARRSIZE, cppPeak, cppTime);

  fprintf(datafile, "SIMD SSE Data:\n"
          "Array Size,Peak Speed,Average Speed\n"
          "%d,%.8f,%.8f\n", ARRSIZE, ssePeak, sseTime);

  fprintf(datafile, "speedupData (C++ Speed / SIMD SSE Speed):\n"
          "Array Size,Peak Speedup,Average Speedup\n"
          "%d,%.8f,%.8f\n", ARRSIZE, (cppPeak/ssePeak), (cppTime/sseTime));

  fprintf(speedupData, "%d,%.8f,%.8f\n", ARRSIZE, (cppPeak/ssePeak), (cppTime/sseTime));

  fclose(datafile);
  fclose(speedupData);

  return 0;
}



//c++ multiplication
void mul(float *A, float *B, float *C, int len)
{
  for(int i = 0; i < len; i++)
    C[i] = A[i] * B[i];
}


//c++ multiplication + reduction
float mulSum(float *A, float *B, int len)
{
  float sum = 0;
  for(int i = 0; i < len; i++)
    sum += A[i] * B[i];

  return sum;
}


float randFloat(unsigned int *seed, float low, float high)
{
  float r = (float) rand_r(seed);

  return(low + r * (high - low) / (float) RAND_MAX);
}


void fillArray(float * array, int size)
{
  unsigned int seed = 0;
  for(int i = 0; i < size; i++)
    array[i] = randFloat(&seed, -1., 1.);
}
