
#Name:		 Christopher Rico
#OSU ID:		 933239746
#Date:		 7/6/17
#Assignment:	 CS 162 - Project 1
#Description: Makefile for langton's ant assignment

CFLAGS = -g -std=c++0x

prog: main.o menu.o ant.o board.o inputVal.o
	g++ ${CFLAGS} main.o menu.o ant.o board.o inputVal.o -o prog

main.o: main.cpp menu.hpp menu.cpp ant.hpp ant.cpp board.hpp board.cpp \
inputVal.hpp inputVal.cpp
	g++ ${CFLAGS} -c main.cpp

menu.o: menu.cpp menu.hpp inputVal.hpp inputVal.cpp
	g++ ${CFLAGS} -c menu.cpp

ant.o: ant.hpp ant.cpp board.hpp board.cpp
	g++ ${CFLAGS} -c ant.cpp

board.o: board.cpp board.hpp
	g++ ${CFLAGS} -c board.cpp


inputVal.o: inputVal.cpp inputVal.hpp
	g++ ${CFLAGS} -c inputVal.cpp


clean:
	rm *.0 prog a.out
