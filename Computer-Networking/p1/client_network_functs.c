/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 5/6/18
Description: Network functions for chatclient.
             Includes a function to set up a socket,
             send a message to the connection,
             and receive a message from the connetion.
***********************************************/

#include "client_network_functs.h"


/*********************************************
 setUpConnection
 Takes a host name and port number in char form as an argument
 Sets up the low-level connection stuff
 Returns the socket file descriptor
 Reference: OTP assignment from CS344 :)
**********************************************/
int setUpConnection(char* hostname, char* port)
{
  char authenticate[] = "PORTNUM\0";
  struct hostent* serverHostInfo;
  struct sockaddr_in serverAddress;
  int socketFD,
      portNum,
      yes = 1;


  //get the port number into int form
  portNum = atoi(port);

  //set up server address struct
  //clear out the address struct
  memset((char*)&serverAddress, '\0', sizeof(serverAddress));
  //create a network-capable socket
  serverAddress.sin_family = AF_INET;
  //store the port number
  serverAddress.sin_port = htons(portNum);
  //convert the machine name into a special form of address
  serverHostInfo = gethostbyname(hostname);

  if(serverHostInfo == NULL)
  {
    fprintf(stderr, "ERROR: no such host\n");
    exit(0);
  }

  memcpy((char*) &serverAddress.sin_addr.s_addr, (char*) serverHostInfo->h_addr, serverHostInfo->h_length);

  //set up socket
  socketFD = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(socketFD, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

  //connect socket to address
  if(connect(socketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0)
    fprintf(stderr, "ERROR connecting to host A\n");


  //send auth token to server
  send(socketFD, authenticate, strlen(authenticate), 0);

  return socketFD;
}


/*********************************************
 sendToServer
Takes a socket descriptor and char* of the message to send
Sends message to designated socket
**********************************************/
void sendToHostA(int sockFD, char* toSend)
{
  char buffer[BUFSIZE];
  int charsWritten = 0;

  //zero out the buffer and copy the message into it
  memset(&buffer, '\0', BUFSIZE);
  //get message into buffer
  strcpy(buffer, toSend);


  //send the message
  charsWritten = send(sockFD, buffer, strlen(buffer), 0);

  if(charsWritten < 0)
    fprintf(stderr, "Error writing to socket");
  if(charsWritten < strlen(buffer))
    fprintf(stderr, "WARNING: Not all data written to socket");

  return;
}


/*********************************************
 recvFromHostA
Takes a socket descriptor and char** to place the recv'd message in
Recv's the message from the given socket
**********************************************/
void recvFromHostA(int sockFD, char** message)
{
  char buffer[BUFSIZE];
  int charsRead = 0;

  //zero out the buffer and copy the message into it
  memset(&buffer, '\0', sizeof(buffer));

  //recieve message from otp_enc_d
  //read the server's message from the socket
  charsRead = recv(sockFD, buffer, BUFSIZE, 0);
  if (charsRead < 0)
    fprintf(stderr, "Error reading message from Host A\n");

  strcpy(*message, buffer);

  return;
}
