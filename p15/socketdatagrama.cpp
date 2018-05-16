#include "socketdatagrama.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>

SocketDatagrama::SocketDatagrama(int port)
{
    s = socket(AF_INET,SOCK_DGRAM,0);

    bzero((char*)& direccionLocal,sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s,(struct sockaddr *) &direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama()
{
    close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
    socklen_t clilen = sizeof(direccionForaena);
    int ret =recvfrom(s,p.obtieneDatos(),p.obtieneLongitud(),0,(struct sockaddr *)&direccionForaena, &clilen);
    char ip[16];
    inet_ntop(AF_INET,&(direccionForaena.sin_addr),ip,INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto(htons(direccionForaena.sin_port));
    return ret;
}

int SocketDatagrama::envia(PaqueteDatagrama & p)
{
    bzero((char*)&direccionForaena, sizeof(direccionForaena));
    direccionForaena.sin_family = AF_INET;
    direccionForaena.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForaena.sin_port = htons(p.obtienePuerto());
    return sendto(s,p.obtieneDatos(),p.obtieneLongitud(),0,(struct sockaddr*) &direccionForaena,sizeof(direccionForaena));
}