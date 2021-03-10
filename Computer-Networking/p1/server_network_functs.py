#Author: Christopher Rico
#OSU ID: 933239746
#Date: 5/6/2018
#Description: Network functions for chatclient.
#             Includes a function to set up a socket,
#             send a message to the connection,
#             and receive a message from the connetion.

import sys
from socket import *


#-------- setUpSocket ----------#
#sets up a socket to listen on with the user-entered port num
#returns set up socket object
#-------------------------------#
def setUpSocket(portNum):
    serverSock = socket(AF_INET,SOCK_STREAM)
    serverSock.bind(('',portNum))

    return serverSock



#-------- checkForKey ----------#
#listens for connection request from client on socket
#returns socket with connection made
#-------------------------------#
def checkForKey(serverSock):
    #listen for inital message of "PORTNUM" from chatclient
    serverSock.listen(1)
    connectionSock, addr = serverSock.accept()

    #get the auth token and decode it
    authByte = connectionSock.recv(8)
    authMessage = authByte.decode('utf-8')
    #checks to see that "PORTNUM" was recvd
    if authMessage != "PORTNUM":
        sys.exit("CONNECTION ERROR: Client did not send correct authentication key.")
    #returns the connection socket if correct key was recieved
    else:
        return connectionSock



#-------- sendToHostB ----------#
#sends a message length (as a string) + message to host B
#-------------------------------#
def sendToHostB(toSend, connectSock):
    #then send the message to hostB first, make sure it's encoded
    connectSock.send(toSend.encode('utf-8'))



#-------- recvFromHostB ----------#
#recv's a message length + message from hostB
#returns the message
#--------------------------------#
def recvFromHostB(connectSock):
    #receieve message from host B
    msgByte = connectSock.recv(512)
    msg = msgByte.decode('utf-8')

    return msg
