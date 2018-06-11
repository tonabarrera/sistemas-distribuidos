#include "SocketMulticast.h"

SocketMulticast::SocketMulticast() {
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == -1){
        perror("SocketMulticast()");
        exit(EXIT_FAILURE);
    }
}

SocketMulticast::~SocketMulticast() {
    close(s);
}

int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char TTL) {
    int resultado = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL));
    if (resultado == -1){
        perror("envia()");
        exit(EXIT_FAILURE);
    }
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion()); // GRUPO
    direccionForanea.sin_port = htons(p.obtienePuerto()); // PUERO DEL GRUPO
    return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketMulticast::recibe(PaqueteDatagrama &p, char *ipE) {
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(p.obtienePuerto());
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));

    multicast.imr_multiaddr.s_addr = inet_addr(ipE);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    int res = setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
    if (res == -1){
        perror("recibe()");
        exit(EXIT_FAILURE);
    }
    char datos[p.obtieneLongitud()];
    char aux[INET_ADDRSTRLEN];
    socklen_t clilen = sizeof(direccionForanea);
    int i = recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &clilen);
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), aux, INET_ADDRSTRLEN);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(aux);
    p.inicializaDatos(datos);
    return i;
}