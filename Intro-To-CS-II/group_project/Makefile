#Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
#Date: 07/30/2017
#Description: Makefile for rock, paper, scissors game

CC = g++
CFLAGS = -g -std=c++0x

#-------------------------------------------------------------------#

prog: play_game.o tool.o rock.o paper.o scissors.o rpsgame.o inputVal.o
	${CC} ${CFLAGS} play_game.o tool.o rock.o paper.o scissors.o rpsgame.o inputVal.o -o prog

play_game.o: play_game.cpp rpsgame.hpp rpsgame.cpp tool.hpp tool.cpp paper.hpp\
paper.cpp rock.hpp rock.cpp scissors.hpp scissors.cpp inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c play_game.cpp

tool.o: tool.hpp tool.cpp
	${CC} ${CFLAGS} -c tool.cpp

rock.o: tool.hpp tool.cpp rock.hpp rock.cpp
	${CC} ${CFLAGS} -c rock.cpp

paper.o: tool.hpp tool.cpp paper.hpp paper.cpp
	${CC} ${CFLAGS} -c paper.cpp

scissors.o: tool.hpp tool.cpp scissors.hpp scissors.cpp
	${CC} ${CFLAGS} -c scissors.cpp

rpsgame.o: rpsgame.hpp rpsgame.cpp tool.hpp tool.cpp paper.hpp paper.cpp\
rock.hpp rock.cpp scissors.hpp scissors.cpp inputVal.cpp inputVal.hpp
	${CC} ${CFLAGS} -c rpsgame.cpp

inputVal.o: inputVal.hpp inputVal.cpp
	${CC} ${CFLAGS} -c inputVal.cpp

clean:
	rm *.o prog a.out
