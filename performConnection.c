#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "protocol.h"
int performConnection (int socket_fd){
    char message[99];
    //S: + MNM Gameserver Gameserver Version accepting connections
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,ACCEPT)==-1){
        return -1;
    }
    //C: VERSION Client Version
    if (sendMessage(socket_fd,"VERSION 2.0\n")==-1){
        return -1;
    }
    //S: + Client version accepted- please send Game-ID to join
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,VERSION)==-1){
        return -1;
    }
    //C: ID Game-ID
    if(sendMessage(socket_fd,"ID 1234\n")==-1){
        return -1;
    }
    //S: + PLAYING Gamekind-Name
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,PLAYING)==-1){
        return -1;
    }
    //S: + Game-Name
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,NAME)==-1){
        return -1;
    }
    //C: PLAYER [[Gewünschte Mitspielernummer]]
    if (sendMessage(socket_fd,"PLAYER\n")==-1){
        return -1;
    }
    //S: + YOU Mitspielernummer Mitspielername
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,YOU)==-1){
        return -1;
    }
    // S: + TOTAL Mitspieleranzahl
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,TOTAL)==-1){
        return -1;
    }
    //S: + Mitspielernummer Mitspielername Bereit
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,OTHER)==-1){
        return -1;
    }
    //S: + ENDPLAYERS
    if (receiveMessage(socket_fd,message,sizeof(message))==-1){
        return -1;
    }
    if (checkResponse(message,ENDPLAYERS)==-1){
        return -1;
    }
    return 0;
}
