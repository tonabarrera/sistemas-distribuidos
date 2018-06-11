#include "Solicitud.h"
#include <cstdlib>
#include <cstring>

Solicitud::Solicitud() {
    socketlocal = new SocketDatagrama(0);
    peticion = 0;
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    struct mensaje *msj = (struct mensaje *) malloc(sizeof(struct mensaje));
    //size_t tam = 4*sizeof(int) + 16*sizeof(char) + strlen(arguments);
    msj->messageType = 0;
    msj->requestId = peticion++;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    PaqueteDatagrama paquete(sizeof(struct mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    short contador = 0;
    while (socketlocal->recibeTimeout(respuesta, 2, 500000) == -1 && contador < 7) {
        contador++;
        socketlocal->envia(paquete);
        printf("%s\n", "Tiempo de recepción transcurrido");
    }

    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));

    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();

    return msj_respuesta->arguments;
}