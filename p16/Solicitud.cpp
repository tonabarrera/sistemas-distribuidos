#include "Solicitud.h"
#include <cstdlib>
#include <cstring>

Solicitud::Solicitud() {
    socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
    size_t tam = 4*sizeof(int) + 16*sizeof(char) + strlen(arguments);
    msj->messageType = 0;
    msj->requestId = 1;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(tam);
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);
    socketlocal->envia(paquete);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    short contador = 0;
    while (socketlocal->recibeTimeout(respuesta, 2, 500000) == -1 && contador < 7) {
        contador++;
        printf("%s\n", "Tiempo de recepción transcurrido");
    }

    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));

    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

    return msj_respuesta->arguments;
}