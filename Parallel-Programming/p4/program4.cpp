/*
  Christopher Rico
  Project 4
  CS475
  OSU ID: 933239746
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <omp.h>

using namespace std;


/*******************************
    Global Value Definitions
*******************************/
unsigned int randSeed;

int	nowYear;		// 2017 - 2022
int	nowMonth;		// 0 - 11

float	nowPrecip;		// inches of rain per month
float	nowTemp;		// temperature this month
float	nowHeight;		// grain height in inches
int	nowNumDeer;		// number of deer in the current population
float nowPlagueEffect;

const float GRAIN_GROWS_PER_MONTH =		150.0;
const float ONE_DEER_EATS_PER_MONTH =		0.5;

const float AVG_PRECIP_PER_MONTH =		20.0;	// average
const float AMP_PRECIP_PER_MONTH =		20.0;	// plus or minus
const float RANDOM_PRECIP =			10.0;	// plus or minus noise

const float AVG_TEMP =				50.0;	// average
const float AMP_TEMP =				20.0;	// plus or minus
const float RANDOM_TEMP =			10.0;	// plus or minus noise

const float AVG_PLAGUE = 10.0;
const float RANDOM_PLAGUE = 5.0;

const float MIDTEMP =				40.0;
const float MIDPRECIP =				10.0;

const float PI = 3.14159;

const int START_YEAR = 2017;
const int END_YEAR = 2023;


/*******************************
      Function Headers
*******************************/
float SQR(float x);
float ranf(unsigned int *seedp, float low, float high);
int ranf(unsigned int *seedp, int ilow, int ihigh);
void setTemp(unsigned int *seed);
void setPrecip(unsigned int * seed);
void grainDeer();
void grainGrowth();
void watcher();
/*
My agent simulates a locust swarm that decimates a grain crop.
It is dependent on the grain size and time of year:
When grain is tall during the summer, locusts strike!
*/
void biblicalPlague();



int main()
{
  #ifndef _OPENMP
      fprintf(stderr, "OpenMP not supported on this machine. Exiting now.\n");
      return 1;
  #endif


  nowMonth = 0;
  nowYear = START_YEAR;
  nowNumDeer = 1;
  nowHeight = 1.;
  nowPlagueEffect = 0.;
  unsigned int randSeed = 0;
  setTemp(&randSeed);
  setPrecip(&randSeed);

  omp_set_num_threads(4);
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      grainDeer();
    }

    #pragma omp section
    {
      grainGrowth();
    }

    #pragma omp section
    {
      watcher();
    }

    #pragma omp section
    {
      biblicalPlague();
    }
  }

  return 0;
}



void grainDeer()
{
  int localDeer;

  while (nowYear < END_YEAR)
  {
    localDeer = nowNumDeer;
    if((float) localDeer > nowHeight)
      localDeer--;
    else if((float) localDeer < nowHeight)
      localDeer++;

    //done computing barrier
    #pragma omp barrier

    nowNumDeer = localDeer;
    //done assigning barrier
    #pragma omp barrier

    ;
    //done printing barrier
    #pragma omp barrier
  }
}



void grainGrowth()
{
  float localHeight;
  float tempFactor;
  float precipFactor;

  while (nowYear < END_YEAR)
  {
    localHeight = nowHeight;
    tempFactor = exp( - SQR((nowTemp - MIDTEMP) * (nowTemp - MIDTEMP)/10.));
    precipFactor = exp( - SQR((nowPrecip - MIDPRECIP) * (nowPrecip - MIDPRECIP)/10.));
    localHeight += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
    localHeight -= (float)nowNumDeer * ONE_DEER_EATS_PER_MONTH;

    //add in the plague effect function
    localHeight -= nowPlagueEffect;

    if(localHeight < 0)
      localHeight = 0;
    //done computing barrier
    #pragma omp barrier

    nowHeight = localHeight;
    //done assigning barrier
    #pragma omp barrier

    ;
    //done printing barrier
    #pragma omp barrier
  }
}



void watcher()
{
  FILE *data = fopen("data.csv", "w+");
  fprintf(data, "Month,Temperature (F),Precipitation (in),Height (in),Plague Effect,GrainDeer\n");


  int month;
  unsigned int randSeed = 0;

  while (nowYear < END_YEAR)
  {
    ;
    //done computing barrier
    #pragma omp barrier

    ;
    //done assigning barrier
    #pragma omp barrier

    month = nowMonth + 12 * (nowYear - START_YEAR);

    fprintf(data, "%d,%.2f,%.2f,%.2f,%.2f,%d\n", month, nowTemp, nowPrecip, nowHeight, nowPlagueEffect, nowNumDeer);

    if(++nowMonth > 11)
    {
      nowMonth = 0;
      nowYear++;
    }

    setTemp(&randSeed);
    setPrecip(&randSeed);

    //done printing
    #pragma omp barrier
  }

  fclose(data);
}



/*******************************
  biblicalPlague fucntion
  Attacks grain with a plague during the winter
  If crop is large enough
*******************************/
void biblicalPlague()
{
  float localPlagueEffect;
  unsigned int randSeed = 0;

  while (nowYear < END_YEAR)
  {
    //during the winter, when crop is growing
    if(nowMonth > 10 || nowMonth < 3)
    {
      //if the crop is sufficiently large enough to support pests
      if(nowHeight > 30.)
        //decimate the crop
        localPlagueEffect = (AVG_PLAGUE + ranf(&randSeed, 0., RANDOM_PLAGUE));
    }
    else
      localPlagueEffect = 0.;

    //done computing barrier
    #pragma omp barrier

    nowPlagueEffect = localPlagueEffect;
    //done assigning
    #pragma omp barrier

    ;
    //done printing barrier
    #pragma omp barrier
  }
}



/**************************************
 Setters and Random Number Generators
***************************************/
float SQR(float x)
{
  return x*x;
}


float _ang()
{
	return (30. * (float) nowMonth + 15.) * (PI / 180.);
}


void setTemp(unsigned int *seed)
{
	float temp = AVG_TEMP - AMP_TEMP * cos(_ang());
	nowTemp = temp + ranf(seed, - RANDOM_TEMP, RANDOM_TEMP);
}


void setPrecip(unsigned int *seed)
{
	float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin(_ang());
	nowPrecip = precip + ranf(seed, - RANDOM_PRECIP, RANDOM_PRECIP);
	if(nowPrecip < 0)
		nowPrecip = 0;
}


float ranf(unsigned int *seedp, float low, float high)
{
	float r = (float) rand_r(seedp);

	return (low + r * (high - low) / (float) RAND_MAX);
}


int ranf(unsigned int *seedp, int ilow, int ihigh)
{
	float low = (float) ilow;
	float high = (float) ihigh + 0.9999f;

	return (int)(ranf(seedp, low, high));
}
