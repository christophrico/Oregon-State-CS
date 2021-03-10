/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 5/6/18
Description: Header file for chatclient message manipulation
***********************************************/


#ifndef CLIENT_MESSAGE_FUNCTS_H
#define CLIENT_MESSAGE_FUNCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

#define BUFSIZE 513


int checkAMessage(char* message);
int getUserMessage(char* handB, char** message);

#endif // CLIENT_MESSAGE_FUNCTS
