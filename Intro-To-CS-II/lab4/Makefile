
#Name:		 		Christopher Rico
#OSU ID:   		933239746
#Date:		 		7/23/17
#Assignment: 	CS 162 - Lab 4
#Description: makefile for university assignment

CC = g++
CFLAGS = -g -std=c++0x
STDOFILES = main.o menu.o inputVal.o
NOVOFILES = university.o person.o student.o instructor.o building.o

#-------------------------------------------------------------------#

prog: main.o inputVal.o menu.o university.o person.o student.o instructor.o building.o
	${CC} ${CFLAGS} ${STDOFILES} ${NOVOFILES} -o prog

main.o: main.cpp inputVal.cpp inputVal.hpp menu.cpp menu.hpp university.cpp\
university.hpp person.cpp person.hpp student.cpp student.hpp instructor.cpp\
instructor.hpp building.cpp building.hpp
	${CC} ${CFLAGS} -c main.cpp

menu.o: menu.cpp menu.hpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c menu.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	${CC} ${CFLAGS} -c inputVal.cpp

university.o: inputVal.hpp inputVal.cpp person.cpp person.hpp student.cpp student.hpp\
instructor.cpp instructor.hpp building.cpp building.hpp university.hpp university.cpp
	${CC} ${CFLAGS} -c university.cpp

person.o: person.hpp person.cpp
	${CC} ${CFLAGS} -c person.cpp

instructor.o: person.hpp person.cpp instructor.hpp instructor.cpp
	${CC} ${CFLAGS} -c instructor.cpp

student.o: person.hpp person.cpp student.hpp student.cpp
	${CC} ${CFLAGS} -c student.cpp

building.o: building.hpp building.cpp
	${CC} ${CFLAGS} -c building.cpp

clean:
	rm *.o prog a.out
