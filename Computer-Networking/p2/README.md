# FTP
A client-server setup that allows for file transfer between two machines on a shared network.

## Instructions to launch ftserve:
1. Place makefile and ftserve.c into the same directory, along with
  any files you may want to transfer from ftserve to ftclient.
2. To compile, enter:
```shell
$ make
```
3. To run, enter:
```
$ ./ftserve <CMD_PORTNUM>
```
4. To exit ftserve, enter Cmd-C.


## Instructions to launch ftclient:
1. Place ftclient into your desired directory.
2. To execute, enter:
```shell
$ chmod +x ftclient
$ ./ftclient <SERVER_HOSTNAME> <CMD_PORTNUM> <DATA_PORTNUM> <COMMAND> <FILENAME>
```
*Please note that <CMD_PORTNUM> must be the same for both ftclient and ftserve!*
