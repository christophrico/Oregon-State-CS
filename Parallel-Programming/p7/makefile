all: ompData simdData openclData


ompData: ompAutoCorrelate.cpp
	g++ -o omp ompAutoCorrelate.cpp -lm -fopenmp
	./omp
	rm -f omp


simdData: simd.cpp simd.h simdAutoCorrelate.cpp
	g++ -o simd simd.cpp simdAutoCorrelate.cpp -lm -fopenmp
	./simd
	rm -f simd


#this compilation command is intended to be used on rabbit
openclData: openclAutoCorrelate.cpp
	g++ -o opencl openclAutoCorrelate.cpp /scratch/cuda-7.0/lib64/libOpenCL.so -lm -fopenmp
	./opencl
	rm -f opencl



clean:
	rm -f *.csv
