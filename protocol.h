#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stddef.h>

enum protocolPhase {
    ACCEPT,
    VERSION,
    PLAYING,
    NAME,
    YOU,
    TOTAL,
    OTHER,
    ENDPLAYERS
};

int sendMessage(int socket_fd, char *message);
int receiveMessage(int socket_fd, char *message, size_t capacity);
int checkResponse(char *message, enum protocolPhase phase);

#endif