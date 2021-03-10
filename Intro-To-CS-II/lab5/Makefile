#Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
#Date: 07/30/2017
#Description: Makefile for rock, paper, scissors game

CC = g++
CFLAGS = -g -std=c++0x

STDOFILES = main.o inputVal.o menu.o
NOVOFILES = rArray.o rString.o rTriangle.o
#-------------------------------------------------------------------#

prog: main.o menu.o inputVal.o menu.o rArray.o rString.o rTriangle.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog

main.o: main.cpp inputVal.cpp inputVal.hpp menu.hpp menu.cpp\
rArray.hpp rArray.cpp rString.hpp rString.cpp rTriangle.hpp rTriangle.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.hpp menu.cpp
	${CC} ${CFLAGS} -c menu.cpp
	
inputVal.o: inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c inputVal.cpp

rArray.o: rArray.hpp rArray.cpp
	${CC} ${CFLAGS} -c rArray.cpp

rTriangle.o: rTriangle.hpp rTriangle.cpp
	${CC} ${CFLAGS} -c rTriangle.cpp

rString.o: rString.hpp rString.cpp
	${CC} ${CFLAGS} -c rString.cpp


clean:
	rm *.o prog a.out
