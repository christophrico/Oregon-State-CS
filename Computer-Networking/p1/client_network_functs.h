/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 5/6/18
Description: Header file for chatclient network functions.
***********************************************/


#ifndef CLIENT_NETWORK_FUNCTS_H
#define CLIENT_NETWORK_FUNCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

#define BUFSIZE 513
#define h_addr h_addr_list[0]

int setUpConnection(char* hostname, char* port);
void sendToHostA(int socketFD, char* toSend);
void recvFromHostA(int sockFD, char** message);


#endif // CLIENT_NETWORK_FUNCTS
