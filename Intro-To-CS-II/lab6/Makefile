#Author: Christopher Rico
# OSU ID: 933239746
#Date: 8/6/2017
#Description: Makefile for queue assignment

CC = g++
CFLAGS = -g -std=c++0x

STDOFILES = main.o inputVal.o menu.o
NOVOFILES = queue.o
#----------------------------------------------------------------------#

prog: main.o menu.o inputVal.o menu.o queue.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog


main.o: main.cpp inputVal.cpp inputVal.hpp menu.hpp menu.cpp queue.hpp queue.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.hpp menu.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp
	
inputVal.o: inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c inputVal.cpp

queue.o: queue.cpp queue.hpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c queue.cpp

clean:
	rm *.o prog a.out
