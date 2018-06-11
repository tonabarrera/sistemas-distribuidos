#include "Respuesta.hpp"
#include "Mensaje.h"

Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
    //size_t tam = 4*sizeof(int) + 16*sizeof(char) + strlen(respuesta);
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(struct mensaje));
    memcpy(msj->arguments, respuesta, strlen(respuesta));
    msj->messageType = 1;
    PaqueteDatagrama p((char *)msj, sizeof(struct mensaje), ipCliente, puertoCliente);
    socketlocal->envia(p);
}

struct mensaje* Respuesta::getRequest(void){
    PaqueteDatagrama p(sizeof(struct mensaje));
    socketlocal->recibe(p);
    struct mensaje * msg = (struct mensaje*) p.obtieneDatos();
    struct mensaje *recibido = (struct mensaje *)malloc(sizeof(struct mensaje));
    recibido->messageType = msg->messageType;
    recibido->requestId = msg->requestId;
    memset(recibido->IP, '\0', 16);
    memcpy(recibido->IP, p.obtieneDireccion(), strlen(p.obtieneDireccion()));
    recibido->puerto = p.obtienePuerto();
    recibido->operationId = msg->operationId;
    memcpy(recibido->arguments, msg->arguments, strlen(msg->arguments));

    return recibido;
}

