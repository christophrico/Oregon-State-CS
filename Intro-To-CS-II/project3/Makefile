#Author: Christopher Rico
# OSU ID: 933239746
#Date: 8/6/2017
#Description: Makefile for fantasy game

CC = g++
CFLAGS = -g -std=c++0x

STDOFILES = main.o inputVal.o menu.o
NOVOFILES = creature.o vamp.o barbarian.o blueman.o medusa.o harry.o\
fantasygame.o
#----------------------------------------------------------------------#

prog: main.o menu.o inputVal.o menu.o fantasygame.o\
creature.o vamp.o barbarian.o blueman.o medusa.o harry.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog


main.o: main.cpp inputVal.cpp inputVal.hpp menu.hpp menu.cpp\
fantasygame.hpp fantasygame.cpp creature.hpp creature.cpp vamp.hpp vamp.cpp\
barbarian.hpp barbarian.cpp blueman.hpp blueman.cpp medusa.hpp medusa.cpp harry.hpp harry.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.hpp menu.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp
	
inputVal.o: inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c inputVal.cpp

fantasygame.o: fantasygame.hpp fantasygame.cpp menu.hpp menu.cpp\
inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c fantasygame.cpp

creature.o: creature.hpp creature.cpp 
	${CC} ${CFLAGS} -c creature.cpp

vamp.o: creature.hpp creature.cpp inputVal.hpp inputVal.cpp vamp.hpp vamp.cpp
	${CC} ${CFLAGS} -c vamp.cpp

barbarian.o: creature.hpp creature.cpp inputVal.hpp inputVal.cpp barbarian.hpp barbarian.cpp
	${CC} ${CFLAGS} -c barbarian.cpp
	
blueman.o: creature.hpp creature.cpp inputVal.hpp inputVal.cpp blueman.hpp blueman.cpp
	${CC} ${CFLAGS} -c blueman.cpp
	
medusa.o: creature.hpp creature.cpp inputVal.hpp inputVal.cpp medusa.hpp medusa.cpp
	${CC} ${CFLAGS} -c medusa.cpp
	
harry.o: creature.hpp creature.cpp inputVal.hpp inputVal.cpp harry.hpp harry.cpp
	${CC} ${CFLAGS} -c harry.cpp


clean:
	rm *.o prog a.out
