#Author: Christopher Rico
#OSU ID: 933239746
#Date: 5/6/2018
#Description: This program implements the "server side"
#             of a networked chat app. User enters port number
#             via the command line, and program will wait for a connection request
#             from a chat "server" on the given port. User can send/receive messages
#             from the client.

import sys
from server_network_functs import *
from server_message_functs import *


def main():
    #check number of cmd-line arguments. if greater than 2, exit and say so
    if len(sys.argv) != 2:
        sys.exit("USAGE: Enter port_number as command-line arg.")

    #set up socket to listen on with user-specified port
    userPort = int(sys.argv[1])
    serverSocket = setUpSocket(userPort)


    #get handle name from user
    print("Welcome to BeaverChat!")
    print("Please enter your handle.")
    handleName = input('Handle should be a single word with up to 10 characters: ')


    #loop until SIGINT
    while 1:
        print("Waiting for a connection from chatclient...")
        #listen for inital message of PORTNUM from chatclient
        #initiate a connection if correct phrase is recieved
        connectionSocket = checkForKey(serverSocket)
        #hosts can now send messages back and forth
        print(handleName + ", you are now connected to a chat mate.")


        #loop until one user enters '/quit'
        while 1:
            #*******SEND MESSAGE******#
            #get the message from the host A user, check it for quit phrase
            quitTestA, msgToSend = getUserMessage(handleName)
            #send the messsage to host B
            sendToHostB(msgToSend, connectionSocket)
            #if user wants to quit
            if quitTestA:
                print("You have left the chat.")
                #close the connection and break out of the loop
                connectionSocket.close()
                break


            #*******RECEIVE MESSAGE******#
            #get the message from host B
            msgRecvd = recvFromHostB(connectionSocket)
            #check it for quit phrase
            quitTestB, handleB =  checkBMessage(msgRecvd)
            #if user wants to quit
            if quitTestB:
                #close the connection and break out of the loop
                print("User " + handleB + " has left the chat.")
                connectionSocket.close()
                break
            else:
                print(msgRecvd)



if __name__ == '__main__':
    main()
