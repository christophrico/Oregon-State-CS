
#Name:		 		Christopher Rico
#OSU ID:     	933239746
#Date:		 		7/24/17
#Assignment: 	CS 162 - Project 2
#Description: makefile for shopping list assignment

CC = g++
CFLAGS = -g -std=c++0x
STDOFILES = main.o menu.o inputVal.o
NOVOFILES = list.o item.o

#------------------------------------------------#

prog: main.o inputVal.o menu.o list.o item.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog

main.o: main.cpp inputVal.cpp inputVal.hpp menu.cpp menu.hpp item.hpp item.cpp list.hpp list.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.cpp menu.hpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	${CC} ${CFLAGS} -c inputVal.cpp

list.o: inputVal.hpp inputVal.cpp list.hpp list.cpp item.hpp item.cpp menu.hpp menu.cpp
	${CC} ${CFLAGS} -c list.cpp

item.o: item.hpp item.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c item.cpp

clean:
	rm *.o prog a.out
