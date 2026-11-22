#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "config.h"

// redefining PORTNUMBER as a char* so we can hand it over to function getaddrinfo
int length = sizeof(PORTNUMBER);
char* newPortnumber = malloc(length + 1);
snprintf(newPortnumber, length + 1, "%d", PORTNUMBER);

// defining *res and hints structs and cleaning them so we get propper infos from getaddrinfo
struct addrinfo *res = NULL;
struct addrinfo hints;
memset(&hints, 0, sizeof(hints));
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;


int status = getaddrinfo(HOSTNAME, newPortnumber, &hints, &res );
free(newPortnumber);
if (status != 0) {
    perror("Could not pull addrinfo from connector");
    return -1;
}

// initiating connection on a socket
int socket_fd = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);

if (socket_fd != -1) {
    perror("Socket coult not be established");
    return -1;
}