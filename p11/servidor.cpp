#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(7200);
    PaqueteDatagrama paquete(4);

    while(1) {
        printf("%s\n", "ESPERANDO...");
        cliente.recibe(paquete);
        printf("Mensaje recibido: %s\n", paquete.obtieneDatos());
        printf("Puerto: %d\n", paquete.obtienePuerto());
        printf("Direccion: %d.%d.%d.%d\n", paquete.obtieneDireccion()[0], paquete.obtieneDireccion()[1], paquete.obtieneDireccion()[2], paquete.obtieneDireccion()[3]);
        printf("%s\n", "RECIBIDO");
    }

    return 0;
}