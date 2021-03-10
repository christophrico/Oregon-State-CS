/*********************************************
Author: Christopher Rico
OSU ID: 933239746
Date: 6/3/18

Description: ftserver program:
This program sets up a socket to listen on a command port specified by cmd-line.
It recieves instructions (command, ip address, data port number and optional filename)
From a client program that is connected to the same command port
ftserver establishes a second data connection with ftclient
Then, depending on the command, either sends over its current directory to ftclient
Or validates and sends a file that is in the current directory.
Then it closes the data connection and waits on the command socket for another connection
***********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>

//allow up to 100 MB of data to be transmitted
#define BUFSIZE 1000

//function prototypes
int startup(char* cmdPortNum);
int createSocket(struct addrinfo * sock);
struct addrinfo* createAddrWithIP(char* ipAddr, char* dataPort);
void connectSock(int sockFD, struct addrinfo * res);
void waitForConnection(int sockFD);
void sendToClient(int sockFD, char* message);
int getDirectory(char** output);
int getFile(char *fileName, char** fileContents);
void handleRequest(int cmdConnect);



/*********************************************
 startup
 Args: the command port number as a char*
 Sets up a listen socket on specified cmd port num
 Returns: Set up command socket
**********************************************/
int startup(char* cmdPortNum)
{
    int status;
    int cmdSockFD;
    struct addrinfo hints;
    struct addrinfo * res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    //create the address info for the command socket on the specified port num
    if((status = getaddrinfo(NULL, cmdPortNum, &hints, &res)) != 0)
    {
      fprintf(stderr,
            "getaddrinfo error: %s\nDid you enter the correct port num?\n",
            gai_strerror(status));
      exit(1);
    }

    //create the socket file descriptor with the specified address info
    cmdSockFD  = createSocket(res);

    //bind socket to port and tell it to listen for incoming connection
    if(bind(cmdSockFD, res->ai_addr, res->ai_addrlen) == -1)
    {
        close(cmdSockFD);
        fprintf(stderr, "Error in binding command socket\n");
        exit(1);
    }
    if(listen(cmdSockFD, 1) == -1)
    {
        close(cmdSockFD);
        fprintf(stderr, "Error in listening on command socket\n");
        exit(1);
    }

    printf("Welcome to ftserve! I am ready to recieve a connection on port %s.\n", cmdPortNum);
    //return the set up command socket
    return cmdSockFD;
}



/*********************************************
 createSocket
 Args: pointer to an addrinfo struct with port num and IP addr saved inside
 Sets up a listen socket using the addrinfo struct
 Returns: Set up socket file descriptor
**********************************************/
int createSocket(struct addrinfo * sK)
{
    int sockfd;
    if ((sockfd = socket((struct addrinfo *)(sK)->ai_family, sK->ai_socktype, sK->ai_protocol)) == -1)
    {
        fprintf(stderr, "Error in creating socket\n");
        exit(1);
    }
    return sockfd;
}



/*********************************************
 createAddrWithIP
 Args: ip address and port num as char *
 Sets up an addrinfo struct with specified ip addr and port num
 Returns: Set up addrinfo struct
**********************************************/
struct addrinfo* createAddrWithIP(char* ipAddr, char* dataPort)
{
    int status;
    struct addrinfo hints;
    struct addrinfo * res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(ipAddr, dataPort, &hints, &res)) != 0)
    {
      fprintf(stderr,
          "getaddrinfo error: %s\nDid you enter the correct IP and port num?\n",
          gai_strerror(status));
      exit(1);
    }

    return res;
}



/*********************************************
 connectSock
 Args: socket file descriptor and addrinfo struct
 Connects a socket FD at address and port num specified in addrinfo struct
 Returns: nothing
**********************************************/
void connectSock(int sockFD, struct addrinfo * res)
{
    int status;
    if ((status = connect(sockFD, res->ai_addr, res->ai_addrlen)) == -1)
    {
        fprintf(stderr, "Error in connecting socket\n");
        exit(1);
    }
}



/*********************************************
 waitForConnection
 Args: connected socket file descriptor
 Loops indefinitely waiting for an incoming connection on cmd port
 Once connection is established, hands off control to handleRequest
 Closes the cmdConnection once handleRequest returns
 Returns: nothing
**********************************************/
void waitForConnection(int sockFD)
{
    struct sockaddr_storage clientAddr;
    socklen_t addrSize;
    int cmdConnection;

    //loop until sigint
    while(1)
    {
        //accept an incoming connection on the command socket
        addrSize = sizeof(clientAddr);
        cmdConnection = accept(sockFD, (struct addrinfo *)&clientAddr, &addrSize);
        //if the connection hasn't happened, keep looping until it does
        if(cmdConnection == -1)
            continue;
        //once the connection happens, hand off control to handleRequest
        handleRequest(cmdConnection);
        //close the connection once the request is complete
        close(cmdConnection);
    }
}



/*********************************************
 sendDirectToClient
 Args: connected socket file descriptor, char* with message to send
 Sends the message on the specified connection
 When message is complete, sends "__done__" to specify end
 Returns: nothing
**********************************************/
void sendDirectToClient(int sockFD, char* message)
{
  int msgSize = strlen(message);
  int bytesToSend = msgSize;
  int bytesWritten;
  char buffer[BUFSIZE];

  memset(buffer, 0, BUFSIZE);
  strcpy(buffer, message);

  void* p = buffer;

  //use while loop to ensure that all parts of message are sent
  while(bytesToSend > 0)
  {
    //get the number of bytes sent
    bytesWritten = send(sockFD, message, msgSize, 0);
    if(bytesWritten < 0)
    {
      fprintf(stderr, "Error writing to socket!\n");
      return;
    }
    //decrement the number of bytes that still need to be sent
    bytesToSend -= bytesWritten;
    //advance the pointer in the char array to the next point
    p += bytesWritten;
  }

  //send DONE message so client knows that the server is finished sending
  memset(buffer, 0, BUFSIZE);
  strcpy(buffer, "__done__");
  send(sockFD, buffer, BUFSIZE, 0);

  return;
}



/*********************************************
 sendDirectToClient
 Args: connected socket file descriptor, char* with filename
 Sends the message on the specified connection 1000 bytes at a time
 When message is complete, sends "__done__" to specify end
 Returns: nothing
**********************************************/
void sendFileToClient(int sockFD, char* fileName)
{
  char buffer[BUFSIZE];
  memset(buffer, 0, sizeof(buffer));

  int fd = open(fileName, O_RDONLY);
  while(1)
  {
    //read data into the buffer from the file
    //store how many bytes we got in from the file
    int bytesRead = read(fd, buffer, sizeof(buffer)-1);
    if(bytesRead == 0)
      break;

    if(bytesRead < 0)
    {
      fprintf(stderr, "Error reading from file\n");
      return;
    }

    void *p = buffer;
    while(bytesRead > 0)
    {
      int bytesWritten = send(sockFD, p, sizeof(buffer), 0);
      if(bytesWritten < 0)
      {
        fprintf(stderr, "Error writing to socket!\n");
        return;
      }
      bytesRead -= bytesWritten;
      p += bytesWritten;
    }
    memset(buffer, 0, sizeof(buffer));
  }
  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "__done__");
  send(sockFD, buffer, sizeof(buffer), 0);

  return;
}


/*********************************************
 getDirectory
 Args: char** to store the contents of the directory in
 Opens pipe with system call of "ls"
 Then captures output and concatenates it into a string
 Returns: 0 for success, -1 for error
**********************************************/
int getDirectory(char** output)
{
  char *cmd = "ls";
  char buf[BUFSIZE];
  char bufTotal[BUFSIZE];
  FILE *fp;

  memset(&buf, '\0', BUFSIZE);
  memset(&bufTotal, '\0', BUFSIZE);

  if ((fp = popen(cmd, "r")) == NULL)
  {
      printf("Error opening pipe!\n");
      return -1;
  }

  while (fgets(buf, BUFSIZE, fp) != NULL)
  {
      //concatenate the directory contents line by line
      strcat(bufTotal, buf);
  }

  if(pclose(fp))
  {
      printf("Command not found or exited with error status\n");
      return -1;
  }

  strcpy(*output, bufTotal);

  return 0;
}



/*********************************************
 getFile
 Args: char* with file name
 First checks that file actually exists in the current directory
 If not, returns 0
 Returns: 0 if file DNE, 1 file exists
**********************************************/
int fileValid(char *fileName)
{
    struct stat sb;
    int fileValid;

    //check filename for validity
    //if filename is invalid
    if(stat(fileName, &sb) != 0)
        fileValid = 0;

    //else if filename is valid
    else
    {
        fileValid = 1;
    }

    return fileValid;
}



/*********************************************
 handleRequest
 Args: set up command connection
 Recieves the desired data port num, client ip addr, and command from ftclient on cmd connection
 Validates command and sends result to ftclient on cmd connection
 Then sets up a data connection with ftclient
 Either sends current directory to ftclient
 Or validates and sends requestes file to ftclient
 Returns: nothing
**********************************************/
void handleRequest(int cmdConnect)
{
    /***************************************************
                 Receive Command From Client
    ***************************************************/
    char dataPortNum[100];
    char clientIPAddr[100];
    char command[100];
    char * debugMsg = "hiyeee";
	  memset(dataPortNum, 0, sizeof(dataPortNum));
    memset(clientIPAddr, 0, sizeof(clientIPAddr));
    memset(command, 0, sizeof(command));

    //recv data port num, command, and client ip addy from client
    //send a message in between each one to prevent python from sending junk
    recv(cmdConnect, dataPortNum, sizeof(dataPortNum)-1, 0);
    send(cmdConnect, debugMsg, strlen(debugMsg),0);
    recv(cmdConnect, command, sizeof(command)-1, 0);
    send(cmdConnect, debugMsg, strlen(debugMsg),0);
    recv(cmdConnect, clientIPAddr, sizeof(clientIPAddr)-1, 0);


    printf("\nIncoming data port num from client is %s\n", dataPortNum);
    printf("Incoming hostname from client is %s\n", clientIPAddr);
    printf("Command from client is %s\n", command);

    //if cmd is valid
    if( (strcmp(command,"-g") == 0) || (strcmp(command,"-l") == 0) )
    {
        //send the client the confirmation that the command is valid
        printf("The command received was valid. Replying to client.\n");
        char* cmdValid = "VC";
        send(cmdConnect, cmdValid, strlen(cmdValid), 0);

        /***************************************************
                      Send Data To Client
        ***************************************************/
        //if client has send -l command
        if( (strcmp(command, "-l") == 0) )
        {
            //give python a couple seconds to set up its listen socket
            sleep(2);
            //set up the data connection
            struct addrinfo *res = createAddrWithIP(clientIPAddr, dataPortNum);
            int dataConnection = createSocket(res);
            connectSock(dataConnection, res);

            //get the contents of the directory
            char* direct = (char *)malloc(BUFSIZE);
            getDirectory(&direct);
            printf("Sending directory to %s on port %s.\n", clientIPAddr, dataPortNum);
            //send directory contents to ftclient on data connection
            sendDirectToClient(dataConnection, direct);
            printf("Transfer complete.\n");

            //free up malloced mem
            free(direct);
        }

        //else if client has sent -g command
        else if( (strcmp(command, "-g") == 0) )
        {
            //get the filename from the client
            char fileName[100];
            memset(fileName, 0, sizeof(fileName));
            recv(cmdConnect, fileName, sizeof(fileName)-1, 0);

            printf("File \"%s\" requested by ftclient.\n", fileName);

            //check filename for validity, if valid, get contents
            char* contents;
            if(fileValid(fileName))
            {
                //send file is valid message on control connection
                char* fileValidMes = "VF";
                send(cmdConnect, fileValidMes, strlen(fileValidMes), 0);

                //give python a couple seconds to set up its listen socket
                sleep(2);
                //set up the data connection
                struct addrinfo * res = createAddrWithIP(clientIPAddr, dataPortNum);
                int dataConnection = createSocket(res);
                connectSock(dataConnection, res);
                printf("Sending file \"%s\" to %s on port %s.\n", fileName, clientIPAddr, dataPortNum);
                //send file content to client on data connection
                sendFileToClient(dataConnection, fileName);
                printf("Transfer complete.\n");
            }

            else
            {
              char* fileInvMes = "ERROR";
              //send client a message on cmd connection that file does not exist
              printf("ERROR: File \"%s\" does not exist. Sending error message to client.\n", fileName);
              send(cmdConnect, fileInvMes, strlen(fileInvMes), 0);
            }
        }
    } // endif valid cmd

    //if command is invalid
    else
    {
        //send error message back to ftclient
        printf("The command received was not valid. Sending an error message to client\n");
        char* errorMessage = "ERROR";
        send(cmdConnect, errorMessage, strlen(errorMessage), 0);
    }

    printf("\nWaiting for incoming connection\n");
}



int main(int argc, char * argv[])
{
    //get and validate portnum passed in via command line
    if(argc != 2 && !isdigit(atoi(argv[1])))
    {
        fprintf(stderr, "USAGE: Enter <PORTNUM> as command-line argument.\n");
        exit(0);
    }

    //create, bind and set up socket to listen on specified cmd port
    int cmdSock = startup(argv[1]);

    //wait for incoming connection on cmd port
    waitForConnection(cmdSock);

    return 0;
}
