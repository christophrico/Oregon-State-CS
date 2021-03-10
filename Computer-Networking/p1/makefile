#Author: Christopher Rico
#OSU ID: 933239746
#Date: 5/6/2018
#Description: Makefile for project 1

CC = gcc
CFLAGS = -g -std=c99

STDCFILES = chatclient.c client_network_functs.c client_message_functs.c
#----------------------------------------------------------------------#

chatclient: chatclient.c client_network_functs.c client_message_functs.c client_message_functs.h client_network_functs.h
	${CC} ${CFLAGS} ${STDCFILES} -o chatclient

clean:
	rm -f chatclient
