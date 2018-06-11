#ifndef __SOCKET_MULTICAST__
#define __SOCKET_MULTICAST__

#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "PaqueteDatagrama.h"

class SocketMulticast {
public:
    SocketMulticast();
    ~SocketMulticast();
    int envia(PaqueteDatagrama &p, unsigned char TTL);
    int recibe(PaqueteDatagrama &p, char *ipE);
private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    struct ip_mreq multicast;
    int s;
};

#endif