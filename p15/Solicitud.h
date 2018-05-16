#ifndef __SOLICITUD__
#define __SOLICITUD__

#include "socketdatagrama.hpp"
#include "paquetedatagrama.hpp"
#include "Mensaje.h"

class Solicitud {
public:
    Solicitud();
    char *doOperation(char *IP, int puerto, int operationId, char *arguments);
private:
    SocketDatagrama *socketlocal;
};
#endif