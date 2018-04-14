#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(7200);
    PaqueteDatagrama paquete(2*sizeof(int));
    PaqueteDatagrama respuesta(1*sizeof(int));
    int a, b, res;
    int num[1];
    while(1) {
        printf("%s\n", "ESPERANDO...");
        cliente.recibe(paquete);
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
        memcpy(&a, paquete.obtieneDatos(), 4*sizeof(char));
        memcpy(&b, paquete.obtieneDatos()+(4*sizeof(char)), 4*sizeof(char));
        res = a + b;
        printf("%d + %d = %d\n", a, b, res);
        num[0] = res;
        respuesta.inicializaPuerto(paquete.obtienePuerto());
        respuesta.inicializaIp(paquete.obtieneDireccion());
        respuesta.inicializaDatos((char *)num);
        
        cliente.envia(respuesta);
        
        printf("%s\n", "RECIBIDO");
    }

    return 0;
}