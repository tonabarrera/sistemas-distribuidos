#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "CLIENTE");
    SocketDatagrama cliente(6666);
    printf("%s\n", "ENVIANDO PAQUETE...");
    PaqueteDatagrama paquete((char *)"Hola", 4, (char *) "127.0.0.1", 7200);
    printf("Mandando paquete a: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
    cliente.envia(paquete);
    printf("%s\n", "PAQUETE ENVIADO");
    return 0;
}
