/*
  Christopher Rico
  Project 7
  CS475
  OSU ID: 933239746
*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <omp.h>

#include "CL/cl.h"
#include "CL/cl_platform.h"

using namespace std;


#define SIZE 32768

#ifndef LOCAL_SIZE
#define	LOCAL_SIZE		64
#endif


void Wait( cl_command_queue queue )
{
      cl_event wait;
      cl_int      status;

      status = clEnqueueMarker( queue, &wait );
      if( status != CL_SUCCESS )
	      fprintf( stderr, "Wait: clEnqueueMarker failed\n" );

      status = clWaitForEvents( 1, &wait );
      if( status != CL_SUCCESS )
	      fprintf( stderr, "Wait: clWaitForEvents failed\n" );
}



int main()
{
  const char *CL_FILE_NAME = "autoCorrelate.cl";

  FILE *fp;
  #ifdef WIN32
  errno_t err = fopen_s( &fp, CL_FILE_NAME, "r" );
  if( err != 0 )
  #else
  fp = fopen( CL_FILE_NAME, "r" );
  if( fp == NULL )
  #endif
  {
    fprintf( stderr, "Cannot open OpenCL source file '%s'\n", CL_FILE_NAME );
    return 1;
  }


  cl_int status;

  //get platform ID
  cl_platform_id platform;
  status = clGetPlatformIDs( 1, &platform, NULL );
  if( status != CL_SUCCESS )
    fprintf( stderr, "clGetPlatformIDs failed (2)\n" );


  //get device ID:
  cl_device_id device;
	status = clGetDeviceIDs( platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clGetDeviceIDs failed (2)\n" );


  //get the signal data
  FILE *fd = fopen("signal.txt", "r");

  if(!fd)
    cout << "Failed to open file." << endl;

  int size;
  fscanf(fd, "%d", &size);
  size = SIZE;


  //allocate the host memory buffers
  float *hArray = new float[ 2*size ];
  float *hSums  = new float[ 1*size ];

  size_t arraySize = 2 * size * sizeof(float);
  size_t sumsSize = size * sizeof(float);


  //fill the host memory buffers
  for(int i = 0; i < size; i++)
  {
    fscanf(fd, "%f", &hArray[i]);
    hArray[i + size] = hArray[i];
  }
  fclose(fd);

  size_t dataSize = size * sizeof(float);


  //create an opencl context
  cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &status);
  if( status != CL_SUCCESS )
    fprintf( stderr, "clCreateContext failed\n" );


  //create an opencl command queue:
	cl_command_queue cmdQueue = clCreateCommandQueue( context, device, 0, &status );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clCreateCommandQueue failed\n" );


  //allocate the device memory buffers:
	cl_mem dArray = clCreateBuffer( context, CL_MEM_READ_ONLY, arraySize, NULL, &status );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clCreateBuffer failed (1)\n" );

  cl_mem dSums = clCreateBuffer( context, CL_MEM_WRITE_ONLY, sumsSize, NULL, &status );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clCreateBuffer failed (2)\n" );


  //enqueue the 2 commands to write the data from the host buffers to the device buffers:
	status = clEnqueueWriteBuffer( cmdQueue, dArray, CL_FALSE, 0, arraySize, hArray, 0, NULL, NULL );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clEnqueueWriteBuffer failed (1)\n" );

	status = clEnqueueWriteBuffer( cmdQueue, dSums, CL_FALSE, 0, sumsSize, hSums, 0, NULL, NULL );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clEnqueueWriteBuffer failed (2)\n" );

  Wait( cmdQueue );


  //read the kernel code from the signal file:
	fseek( fp, 0, SEEK_END );
	size_t fileSize = ftell( fp );
	fseek( fp, 0, SEEK_SET );
	char *clProgramText = new char[ fileSize+1 ];		// leave room for '\0'
	size_t n = fread( clProgramText, 1, fileSize, fp );
	clProgramText[fileSize] = '\0';
	fclose( fp );
	if( n != fileSize )
		fprintf( stderr, "Expected to read %d bytes read from '%s' -- actually read %d.\n", (int) fileSize, CL_FILE_NAME, (int) n );


  // create the text for the kernel program:
	char *strings[1];
	strings[0] = clProgramText;
	cl_program program = clCreateProgramWithSource( context, 1, (const char **)strings, NULL, &status );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clCreateProgramWithSource failed\n" );
	delete [ ] clProgramText;


  //compile and link the kernel code
  const char *options = { "" };
  status = clBuildProgram(program, 1, &device, options, NULL, NULL);
  if(status != CL_SUCCESS)
  {
    size_t size;
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &size);
    cl_char *log = new cl_char[ size ];
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, size, log, NULL);
    fprintf(stderr, "clBuildProgram failed:\n%s\n", log);
    delete [ ] log;
  }


  //create the kernel object
  cl_kernel kernel = clCreateKernel( program, "AutoCorrelate", &status );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clCreateKernel failed\n" );


  //set up arguments to the kernel object
  status = clSetKernelArg( kernel, 0, sizeof(cl_mem), &dArray );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clSetKernelArg failed (1)\n" );

  status = clSetKernelArg( kernel, 1, sizeof(cl_mem), &dSums );
	if( status != CL_SUCCESS )
		fprintf( stderr, "clSetKernelArg failed (2)\n" );


  //enqueue the kernel object for execution
  size_t globalWorkSize[3] = { size, 1, 1 };
  size_t localWorkSize[3]  = { LOCAL_SIZE, 1, 1 };

  Wait(cmdQueue);

  //execute and time it
  double startTime = omp_get_wtime();
  status = clEnqueueNDRangeKernel( cmdQueue, kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL );
  if( status != CL_SUCCESS )
    fprintf( stderr, "clEnqueueNDRangeKernel failed: %d\n", status );

  Wait(cmdQueue);
  double endTime = omp_get_wtime();


  //read the results buffer back from the device to the host
  status = clEnqueueReadBuffer( cmdQueue, dSums, CL_TRUE, 0, sumsSize, hSums, 0, NULL, NULL );
	if( status != CL_SUCCESS )
			fprintf( stderr, "clEnqueueReadBuffer failed\n" );

  Wait(cmdQueue);


  fd = fopen("openclResults.csv", "w");
  fprintf(fd, "Peak Performance (MegaLoops/s)\n");
  fprintf(fd, "%lf\n", (double)size*size / (endTime - startTime) / 1000000);

  fprintf(fd, "Index,Sum\n");
  for(int i = 0; i<size; i++)
  {
    fprintf(fd, "%d,%f\n", i, hSums[i]);
  }
  fclose(fd);


  //clean up
  clReleaseKernel(        kernel   );
  clReleaseProgram(       program  );
  clReleaseCommandQueue(  cmdQueue );
  clReleaseMemObject(     dArray  );
  clReleaseMemObject(     dSums  );

  delete [ ] hArray;
  delete [ ] hSums;


  return 0;
}
