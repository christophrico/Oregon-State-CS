#Author:		Christopher Rico
# OSU ID:		933239746
#Date:			8/16/2017
#Description:	Makefile for final project

CC = g++
CFLAGS = -g -std=c++0x

STDOFILES = main.o inputVal.o menu.o
NOVOFILES = pack.o player.o space.o art.o nineoclock.o deepplaya.o\
distrikt.o rv.o temple.o man.o
#----------------------------------------------------------------------#

prog: main.o inputVal.o menu.o pack.o player.o space.o nineoclock.o\
deepplaya.o distrikt.o rv.o temple.o man.o art.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog


main.o: main.cpp inputVal.cpp inputVal.hpp menu.hpp menu.cpp player.hpp player.cpp\
pack.hpp pack.cpp space.hpp space.cpp nineoclock.hpp nineoclock.cpp man.hpp man.cpp\
deepplaya.hpp deepplaya.cpp distrikt.hpp distrikt.cpp rv.hpp rv.cpp temple.hpp temple.cpp\
art.hpp art.cpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.hpp menu.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp

inputVal.o: inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c inputVal.cpp

pack.o: pack.hpp pack.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c pack.cpp

player.o: player.hpp player.cpp pack.hpp pack.cpp space.hpp space.cpp\
nineoclock.hpp nineoclock.cpp deepplaya.hpp deepplaya.cpp distrikt.hpp distrikt.cpp\
rv.hpp rv.cpp rv.hpp rv.cpp man.hpp man.cpp temple.hpp temple.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c player.cpp

space.o: space.hpp space.cpp inputVal.hpp inputVal.cpp pack.hpp pack.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c space.cpp

nineoclock.o: space.hpp space.cpp inputVal.hpp inputVal.cpp nineoclock.hpp nineoclock.cpp\
pack.hpp pack.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c nineoclock.cpp

distrikt.o: space.hpp space.cpp inputVal.hpp inputVal.cpp distrikt.hpp distrikt.cpp\
pack.hpp pack.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c distrikt.cpp

deepplaya.o: space.hpp space.cpp inputVal.hpp inputVal.cpp deepplaya.hpp deepplaya.cpp\
pack.hpp pack.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c deepplaya.cpp

rv.o: space.hpp space.cpp inputVal.hpp inputVal.cpp rv.hpp rv.cpp pack.hpp pack.cpp\
art.hpp art.cpp
	${CC} ${CFLAGS} -c rv.cpp

man.o: space.hpp space.cpp inputVal.hpp inputVal.cpp man.hpp man.cpp pack.hpp pack.cpp\
art.hpp art.cpp
	${CC} ${CFLAGS} -c man.cpp

temple.o: space.hpp space.cpp inputVal.hpp inputVal.cpp temple.hpp temple.cpp\
pack.hpp pack.cpp art.hpp art.cpp
	${CC} ${CFLAGS} -c temple.cpp

art.o: art.hpp art.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c art.cpp

clean:
	rm *.o prog
