#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "config.h"

int length = sizeof(PORTNUMBER);
char* newPortnumber = malloc(lenght + 1);
snprintf(newPortnumber, lenght +1, "%s", PORTNUMBER);

struct addrinfo *res = NULL;
struct addrinfo hints;
memset(&hints, 0, sizeof(hints));
hints.ai_famili = AF_UNSPEC;
hints.ai_socktype = 0;

int status = getaddrinfo(HOSTNAME, newPortnumber, &hints, &res )
