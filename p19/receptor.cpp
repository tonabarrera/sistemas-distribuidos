#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "RECEPTOR");
    SocketMulticast socket;
    int res[1];
    int numeros[2];
    while (true) {
        PaqueteDatagrama paqueteRecibido(2*sizeof(int));
        socket.recibe(paqueteRecibido, (char *)"239.255.255.42");
        memcpy(numeros, paqueteRecibido.obtieneDatos(), 2*sizeof(int));
        res[0] = numeros[0] + numeros[1];
        printf("%d + %d = %d\n", numeros[0], numeros[1], res[0]);
        SocketDatagrama socketEnvio(7600);
        PaqueteDatagrama paqueteEnviado((char *)res, sizeof(int), paqueteRecibido.obtieneDireccion(), paqueteRecibido.obtienePuerto());
        socketEnvio.envia(paqueteEnviado);
    }
    return 0;
}