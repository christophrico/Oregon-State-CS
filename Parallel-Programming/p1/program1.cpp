/*
 Christopher Rico
 Project 1
 CS475
 OSU ID: 933239746
*/

using namespace std;

#include <iostream>
#include <cstdio>
#include <omp.h>
#include <cstdlib>
#include <sstream>


#define XMIN	 0.
#define XMAX	 3.
#define YMIN	 0.
#define YMAX	 3.

#define TOPZ00  0.
#define TOPZ10  1.
#define TOPZ20  0.
#define TOPZ30  0.

#define TOPZ01  1.
#define TOPZ11  6.
#define TOPZ21  1.
#define TOPZ31  0.

#define TOPZ02  0.
#define TOPZ12  1.
#define TOPZ22  0.
#define TOPZ32  4.

#define TOPZ03  3.
#define TOPZ13  2.
#define TOPZ23  3.
#define TOPZ33  3.

#define BOTZ00  0.
#define BOTZ10  -3.
#define BOTZ20  0.
#define BOTZ30  0.

#define BOTZ01  -2.
#define BOTZ11  10.
#define BOTZ21  -2.
#define BOTZ31  0.

#define BOTZ02  0.
#define BOTZ12  -5.
#define BOTZ22  0.
#define BOTZ32  -6.

#define BOTZ03  -3.
#define BOTZ13   2.
#define BOTZ23  -8.
#define BOTZ33  -3.



float test_height(int iu, int iv)
{
	return 1.0;
}



// iu,iv = 0 .. NUMNODES - 1
float Height( int iu, int iv, int NUMNODES)
{
	float u = (float)iu / (float)(NUMNODES - 1);
	float v = (float)iv / (float)(NUMNODES - 1);

	// the basis functions:
	float bu0 = (1.-u) * (1.-u) * (1.-u);
	float bu1 = 3. * u * (1.-u) * (1.-u);
	float bu2 = 3. * u * u * (1.-u);
	float bu3 = u * u * u;

	float bv0 = (1.-v) * (1.-v) * (1.-v);
	float bv1 = 3. * v * (1.-v) * (1.-v);
	float bv2 = 3. * v * v * (1.-v);
	float bv3 = v * v * v;

	     // finally, we get to compute something:
        float top =       bu0 * ( bv0*TOPZ00 + bv1*TOPZ01 + bv2*TOPZ02 + bv3*TOPZ03 )
                        + bu1 * ( bv0*TOPZ10 + bv1*TOPZ11 + bv2*TOPZ12 + bv3*TOPZ13 )
                        + bu2 * ( bv0*TOPZ20 + bv1*TOPZ21 + bv2*TOPZ22 + bv3*TOPZ23 )
                        + bu3 * ( bv0*TOPZ30 + bv1*TOPZ31 + bv2*TOPZ32 + bv3*TOPZ33 );

        float bot =       bu0 * ( bv0*BOTZ00 + bv1*BOTZ01 + bv2*BOTZ02 + bv3*BOTZ03 )
                        + bu1 * ( bv0*BOTZ10 + bv1*BOTZ11 + bv2*BOTZ12 + bv3*BOTZ13 )
                        + bu2 * ( bv0*BOTZ20 + bv1*BOTZ21 + bv2*BOTZ22 + bv3*BOTZ23 )
                        + bu3 * ( bv0*BOTZ30 + bv1*BOTZ31 + bv2*BOTZ32 + bv3*BOTZ33 );

        // if the bottom surface sticks out above the top surface
        // then that contribution to the overall volume is negative
        return top - bot;
}



int main (int argc, char* argv[])
{
  #ifndef _OPENMP
    std::fprintf(stderr, "OpenMP not supported on this machine. Exiting program.\n");
    return 1;
  #endif

  //get user-indicated file from cmd-line arg
  FILE *datafile = std::fopen(argv[1], "a");

  //get the number of threads and nodes from cmd-line args
  istringstream nt(argv[2]);
  int NUMTHREADS;
  if (!(nt >> NUMTHREADS))
    cerr << "Invalid number " << argv[2] << '\n';

  istringstream nn(argv[3]);
  int NUMNODES;
  if (!(nn >> NUMNODES))
    cerr << "Invalid number " << argv[3] << '\n';


  double volume,
         dx = ((float)(XMAX - XMIN)/(float)NUMNODES),
         dy = ((float)(YMAX - YMIN)/(float)NUMNODES),
         ave_mega_calcs = 0,
         max_mega_calcs = 0,
         mega_calcs;


  omp_set_num_threads(NUMTHREADS);


  for (int i = 0; i < 100; i++)
  {
    double t_not = omp_get_wtime();
    volume = 0.0;

    #pragma omp parallel for default(none), shared(dy, dx, NUMNODES), reduction(+:volume)
    for(int j = 0; j < NUMNODES*NUMNODES; j++)
    {
      int jx = j % NUMNODES;
      int jy = j / NUMNODES;

      //calculate tile volumes
      //full tile
      double dvolume = dx*dy*Height(jx, jy, NUMNODES);

      //reduce vol by half if on the side (x-axis)
      if(jx == 0 || jx == NUMNODES - 1)
        dvolume *= 0.5;
      //reduce vol by half if on the side (y-axis)
      if(jy == 0 || jx == NUMNODES - 1)
        dvolume *= 0.5;

      //add to volume
      volume += dvolume;

    }

    //calculate millions of vol calculations per second
    mega_calcs = (double)(NUMNODES*NUMNODES) / (omp_get_wtime() - t_not) / 1000000;
    if(mega_calcs > max_mega_calcs)
      max_mega_calcs = mega_calcs;

    ave_mega_calcs += mega_calcs;
  }

  std::fprintf(datafile, "%d,%d,%lf,%lf,%lf\n", NUMTHREADS, NUMNODES, volume, max_mega_calcs, ave_mega_calcs/100);
  std::fclose(datafile);
}
