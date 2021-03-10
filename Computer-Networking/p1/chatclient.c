/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 5/6/18
Description: Chatclient.c. This program implements the "client side"
             of a networked chat app. User enters hostname and port number
             via the command line, and program will attempt to connect with a
             chat "server" on the hostname and port. User can send/receive messages
             from the server.
***********************************************/


#include "client_network_functs.h"
#include "client_message_functs.h"


int main(int argc, char *argv[])
{
  int socketFD,
      quitTestA,
      quitTestB,
      portNumber;
  char* messageToSend;
  char* messageToRecv;
  char* handleA;
  char* handleB;
  char  handle[11];


  //check usage and args
  if(argc != 3)
  {
    fprintf(stderr, "USAGE: Enter host_name port_num as command-line args.\n");
    exit(0);
  }

  printf("Welcome to BeaverChat!\n");

  //get handle from user
  memset(&handle, '\0', sizeof(handle));
  printf("Please enter your handle.\nHandle should be a single word with up to 10 characters: ");
  fgets(handle, sizeof(handle), stdin);
  //removes the newline at the end
  int v;
  for (v = 0; v < sizeof(handle); v++)
  {
    if (handle[v] == '\n')
        handle[v] = '\0';
  }
  handleB = (char *)malloc(strlen(handle)+1);
  strcpy(handleB, handle);


  //set up the connection with the server
  socketFD = setUpConnection(argv[1], argv[2]);
  printf("%s, you are now connected to a chat mate.\n", handleB);



  //send and receive until one user inputs '\quit'
  while(1)
  {
    /*******RECEIVE MESSAGE******/
    //allocate heap space for strings
    messageToRecv = (char *)malloc(BUFSIZE);
    //receive message from host A
    recvFromHostA(socketFD, &messageToRecv);

    //check it for quit phrase
    quitTestA = checkAMessage(messageToRecv);
    //if host A wants to quit
    if(quitTestA)
    {
      //close the connection and break out of the the loop
      printf("Your chat partner has left the chat :(.\n");
      close(socketFD);
      break;
    }
    else if(messageToRecv != NULL)
      printf("%s\n", messageToRecv);


    /*******SEND MESSAGE******/
    //get the message from the host B user, check it for quit phrase
    //and prepend the user handle
    messageToSend = (char *)malloc(BUFSIZE);
    quitTestB = getUserMessage(handleB, &messageToSend);

    //send message to host A
    sendToHostA(socketFD, messageToSend);
    //if host B wants to quit
    if(quitTestB)
    {
      //close the connection and break out of the loop
      printf("You have left the chat.\n");
      close(socketFD);
      break;
    }
  }

  free(handleB);
  free(messageToRecv);
  free(messageToSend);
  return 0;
}
