#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(atoi(argv[1]));
    PaqueteDatagrama paquete(3*sizeof(unsigned int));
    PaqueteDatagrama respuesta(1*sizeof(int));
    int num[1];
    while(1) {
        unsigned int n[3], i, a=0;

        printf("%s\n", "ESPERANDO...");
        cliente.recibe(paquete);
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());

        memcpy((char*)n, paquete.obtieneDatos(), 3*sizeof(unsigned int));
        printf("Mensaje recibido: %u\n", n[0]);
        printf("%u %u\n",n[1], n[2]);
        printf("%s\n", "RECIBIDO");

        for(i = n[1]; i<n[2]; i++){
            if((n[0] % i) == 0){
                a++;
                break;
            }
        }

        if(a>0){
            num[0]=0;
            printf("NO PRIMO\n");
        } else{
            printf("PRIMO\n");
            num[0]=1;
        }

        respuesta.inicializaPuerto(paquete.obtienePuerto());
        respuesta.inicializaIp(paquete.obtieneDireccion());
        respuesta.inicializaDatos((char *)num);
        cliente.envia(respuesta);

    }

    return 0;
}
