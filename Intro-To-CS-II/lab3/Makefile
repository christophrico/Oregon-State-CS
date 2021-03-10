
#Name:		 		Christopher Rico
#OSU ID:   		933239746
#Date:		 		7/16/17
#Assignment: 	CS 162 - Lab 3
#Description: Makefile for war game assignment

CC = g++
CFLAGS = -g -std=c++0x

STDOFILES = main.o menu.o inputVal.o

NOVOFILES = game.o die.o loadedDie.o

prog: main.o inputVal.o menu.o game.o die.o loadedDie.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES}  -o prog

main.o: main.cpp inputVal.cpp inputVal.hpp menu.cpp menu.hpp game.hpp game.cpp die.hpp die.cpp loadedDie.hpp loadedDie.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.cpp menu.hpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	${CC} ${CFLAGS} -c inputVal.cpp

game.o: game.hpp game.cpp die.hpp die.cpp loadedDie.hpp loadedDie.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c game.cpp

die.o: die.hpp die.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c die.cpp

loadedDie.o: die.hpp die.cpp loadedDie.hpp loadedDie.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c loadedDie.cpp


clean:
	rm *.o prog a.out
