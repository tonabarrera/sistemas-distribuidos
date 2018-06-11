#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "EMISOR");
    int dato[2] = {5, 7};
    int res[1];
    SocketMulticast socket;
    PaqueteDatagrama paqueteEnviado((char*)dato, 2*sizeof(int), (char *)"239.255.255.42", 7200);
    printf("Enviados = %d\n", socket.envia(paqueteEnviado, 255));
    SocketDatagrama socketRecibir(7200); // ¿En que puerto deberia escuchar?
    while(true) {
        printf("%s\n", "Esperando...");
        PaqueteDatagrama paqueteRecibido(sizeof(int));
        printf("Recibidos = %d\n", socketRecibir.recibe(paqueteRecibido));
        memcpy(res, paqueteRecibido.obtieneDatos(), sizeof(int));
    }
    return 0;
}