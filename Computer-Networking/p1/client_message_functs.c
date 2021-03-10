/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 5/6/18
Description: Message manipulation functions for chatclient.
             Includes a function to check a message for '\quit'
             and function to get and format a user message.
***********************************************/

#include "client_message_functs.h"


/*********************************************
checkAMessage
Takes a char* with the message to be scanned
Scans for '\quit' phrase in msg and passes back out a 1 or 0
**********************************************/
int checkAMessage(char* message)
{
  int quit = 0;

  //check that hostA does not want to quit
  if (*(message + 6) == '\\' &&
      *(message + 7) == 'q' &&
      *(message + 8) == 'u' &&
      *(message + 9) == 'i' &&
      *(message + 10) == 't')
          quit = 1;

  return quit;
}


/*********************************************
getUserMessage
Takes a char* containing the user's handle
And a char** to store the complete outgoing message
Gets the message to be sent from the user, checks it for '\quit' phrase
Prepends the user's handle on to the message
If message is '\quit', it passes back out a 1
**********************************************/
int getUserMessage(char* handB, char** message)
{
  int quit = 0;
  char fromUser[BUFSIZE];
  char outBuf[BUFSIZE];

  //zero out the two buffers for use
  memset(&fromUser, '\0', BUFSIZE);
  memset(&outBuf, '\0', BUFSIZE);

  //print the user's handle to the screen as a prompt
  printf("%s> ", handB);

  //get the message from user
  fgets(fromUser, BUFSIZE, stdin);
  //removes the newline at the end
  int v;
  for (v = 0; v < BUFSIZE; v++)
  {
    if (fromUser[v] == '\n')
        fromUser[v] = '\0';
  }


  //check that userB does not want to quit
  if(strcmp(fromUser, "\\quit") == 0)
    quit = 1;


  //concatenate it all into one nice string
  strcat(outBuf, handB);
  strcat(outBuf, "> ");
  strcat(outBuf, fromUser);
  strcpy(*message, outBuf);

  return quit;
}
