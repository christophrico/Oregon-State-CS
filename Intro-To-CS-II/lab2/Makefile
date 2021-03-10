
#Name:		 Christopher Rico
#OSU ID:		 933239746
#Date:		 7/2/17
#Assignment:	 CS 162 - Project 1
#Description: Client code for matrix assignment. Asks user to select
#			 a 2x2 or 3x3 matrix, then allocates the array for the
#			 matrix. Calls a function to fill the matrix,
#			 then another function to get the determinate of the
#			 matrix. Then, it de-allocates the array.

CFLAGS = -g -std=c++0x

STDOFILES = main.o menu.o inputVal.o
NOVOFILES = letters.o

STDCPPFILES = main.cpp menu.cpp inputVal.cpp
STDHPPFILES = menu.hpp inputVal.hpp

prog: main.o inputVal.o menu.o letters.o
	g++ ${CFLAGS} ${STDOFILES} ${NOVOFILES}  -o prog

main.o: main.cpp inputVal.cpp inputVal.hpp menu.cpp menu.hpp letters.cpp letters.hpp
	g++ ${CFLAGS} -c main.cpp

menu.o: menu.cpp menu.hpp inputVal.hpp inputVal.cpp
	g++ ${CFLAGS} -c menu.cpp

letters.o: letters.hpp letters.cpp
	g++ ${CFLAGS} -c letters.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ ${CFLAGS} -c inputVal.cpp


clean:
	rm *.0 prog a.out
