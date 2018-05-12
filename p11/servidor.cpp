#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(7200);
    PaqueteDatagrama paquete(2*sizeof(double));
    //int a, b, res;
    //int num[1];
    double a, b;
    double g = 777;
    char prueba[sizeof(double)];
    char otro[sizeof(double)];
    char otro2[sizeof(double)];
    while(1) {
        printf("%s\n", "ESPERANDO...");
        printf("Recibidos = %d\n", cliente.recibe(paquete));
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());

        for (int i = 0; i < 8; i++){
            otro[i] = paquete.obtieneDatos()[7-i];
            otro2[i] = paquete.obtieneDatos()[15-i];
        }
        
        memcpy(&a, otro, sizeof(double));
        memcpy(&b, otro2, sizeof(double));

        printf("RECIBIDO = %x %x %x %x %x %x %x %x\n", otro[0], otro[1], otro[2], otro[3], otro[4], otro[5], otro[6], otro[7]);
        memcpy(prueba, &g, sizeof(double));
        printf("REAL= %x %x %x %x %x %x %x %x\n", prueba[0], prueba[1], prueba[2], prueba[3], prueba[4], prueba[5], prueba[6], prueba[7]);
        printf("Res = %f %f\n", a, b);
        /*
        memcpy(&a, paquete.obtieneDatos(), 4*sizeof(char));
        memcpy(&b, paquete.obtieneDatos()+(4*sizeof(char)), 4*sizeof(char));
        res = a + b;
        printf("%d + %d = %d\n", a, b, res);
        num[0] = res;
        respuesta.inicializaPuerto(paquete.obtienePuerto());
        respuesta.inicializaIp(paquete.obtieneDireccion());
        respuesta.inicializaDatos((char *)num);
        
        cliente.envia(respuesta);
        */
        printf("%s\n", "RECIBIDO");
    }

    return 0;
}