#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(7200);
    PaqueteDatagrama paquete(4);

    while(1) {
        printf("%s\n", "ESPERANDO...");
        cliente.recibe(paquete);
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
        printf("Mensaje recibido: %s\n", paquete.obtieneDatos());
        printf("%s\n", "RECIBIDO");
    }

    return 0;
}