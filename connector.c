#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "config.h"

// redefining PORTNUMBER as a char* so we can hand it over to function getaddrinfo
int length = 4;
char* newPortnumber = malloc(length + 1);
snprintf(newPortnumber, length + 1, "%d", PORTNUMBER);

// defining *res and hints structs and cleaning them so we get propper infos from getaddrinfo
struct addrinfo *result = NULL;
struct addrinfo hints;
memset(&hints, 0, sizeof(hints));
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;


int status = getaddrinfo(HOSTNAME, newPortnumber, &hints, &result );
free(newPortnumber);
if (status != 0) {
        printf("%s/n",gai_strerror(status));
        return -1;
}

// initiating connection on a socket
int socket_fd = socket(result -> ai_family, result -> ai_socktype, result -> ai_protocol);

if (socket_fd == -1) {
    perror("Socket could not be established");
    return -1;
}


// initiating the connection to a server
int check_connect = connect(socket_fc, result -> ai_addr, result -> ai_addrlen);

if (check_connect == -1) {
    perror("Could not connect to server!");
    return -1;
}
else if (check_connect == 0) {
    printf("Connection established successfully/n");
}

close(socked_fd);

