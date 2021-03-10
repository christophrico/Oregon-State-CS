#Author: Christopher Rico
#OSU ID: 933239746
#Date: 5/6/2018
#Description: Message manipulation functions for chatserve.
#             Includes a function to check a message for '\quit'
#             and function to get and format a user message.



#-------- getUserMessage ----------#
#gets the message from host A user, checks it for quit phrase
#and prepends the host A handle to the message
#returns quit bool and the message to send
#----------------------------------#
def getUserMessage(handle):
    #get message from user to send to host B
    message = input(handle + "> ")

    #check user's message to see if they want to quit or not
    if message == "\quit":
        quit = True
    else:
        quit = False

    #prepend host A's handle to message
    msgSend = handle + "> " + message

    return quit, msgSend



#-------- checkBMessage ----------#
#checks that the host B user has not sent a quit phrase
#returns quit bool and host B handle
#----------------------------------#
def checkBMessage(message):
    #split the content and handle into two variables
    msgHandle, msgContent = message.split("> ")

    #check user's message to see if they want to quit or not
    if msgContent == "\quit":
        quit = True
    else:
        quit = False

    return quit, msgHandle
