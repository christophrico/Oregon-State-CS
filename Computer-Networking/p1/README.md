# Chatserve
A client-server program that allows for a rudimentary IM system between machines on a shared network.


## Instructions to launch chatserve:
1. Place chatserve.py, messageFuncts.py, networkFuncts.py, and chatserve in the same directory.
2. To execute, enter:
```shell
  $ ./chatserve <port_number>
```
3. Chatserve will run on the specified port number.
4. To exit chatserve, enter Ctrl-c


## Instructions to launch chatclient:
1. Place chatclient.c,  in the same directory
2. To compile, enter:
```shell
  $ make
```
3. To execute, enter:
```shell
  $ ./chatclient <host_name> <port_number>
```
4. Chatclient will run on the specified host name and port number.
5. To exit chatclient, enter '\quit' when prompted to send a message.

*Please note that user-defined port numbers must be the same for the program to work correctly.*
