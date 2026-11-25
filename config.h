#define HOSTNAME "sysprak.priv.lab.nm.ifi.lmu.de"
#define PORTNUMBER 1357
#define GAMEKINDNAME "Reversi"



struct addrinfo {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    socklen_t        ai_addrlen;
    struct sockaddr *ai_addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;
};