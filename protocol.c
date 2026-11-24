#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include "protocol.h"
int sendMessage(int socket_fd, char *message){
    int sent = 0;
    int length=strlen(message);
    int result;
    while(sent<length){
        result = send(socket_fd, message + sent, length - sent, 0);
        if (result == -1){
            return -1;
        }
        sent += result;
    }
    return 0;
}
int receiveMessage( int socket_fd, char *message, size_t capacity){
    size_t received =0;
    ssize_t result=0;
    while (received == 0||message[received -1]!='\n'){
        if (received >= capacity -1){
            return -1;
        }
        result = recv(socket_fd,message + received, capacity-1-received,0);
        if (result <=0){
            return -1;
        }
        received += result;
    }
    message[received]='\0';
    return 0;
}
int checkResponse(char *message, enum protocolPhase phase){
    char *msg = strdup(message);
    if (msg==NULL){
        return -1;
    }
    if (message[0]=='-'){
        free(msg);
        return -1;
    }
    switch (phase) {
        case ACCEPT:
            strtok(msg," ");
            strtok(NULL," ");
            strtok(NULL," ");
            char *version = strtok(NULL," ");
            break;

        case VERSION:
            // muss eigentlich nichts gemacht werden
            break;

        case PLAYING:
            strtok(msg," ");
            strtok(NULL, " ");
            if (strcmp("Reversi",strtok(NULL," "))!=0){
                free(msg);
                return -1;
            }
            break;
        case NAME:
            strtok(msg," ");
            char *gameName=strtok(NULL, " ");
            break;
        case YOU:
            strtok(msg," ");
            strtok(NULL, " ");
            char *meNummer=strtok(NULL, " ");
            char *meName=strtok(NULL, " ");
            break;
        case TOTAL:
            strtok(msg," ");
            strtok(NULL, " ");
            if (strcmp("2",strtok(NULL," "))!=0){
                free(msg);
                return -1;
            }
            break;
        case OTHER:
            strtok(msg," ");
            char *msNummer=strtok(NULL, " ");
            char *msName=strtok(NULL, " ");
            char *bereit=strtok(NULL," ");
            break;
        case ENDPLAYERS:
            // muss eigentlich nichts tun
            break;
        default:
            free(msg);
            return -1;
    }
    free(msg);
    return 0;
}