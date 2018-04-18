#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
	
	unsigned int  num1[3], num2[3], inicio, mitad;
	int n = 11;
	mitad=(int)n/2;
   	inicio=2;
   	num1[0]=n;
   	num1[1]=inicio;
   	num1[2]=mitad;

	num2[0] = n;
	num2[1] = mitad;
	num2[2] = n-1;

    printf("%s\n", "CLIENTE");
    SocketDatagrama cliente(6666);
    printf("%s\n", "ENVIANDO PAQUETE...");

    PaqueteDatagrama paquete((char *)num1, 3*sizeof(unsigned int), (char *) "127.0.0.1", 7200);
    printf("Mandando paquete a: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());
    cliente.envia(paquete);
    printf("%s\n", "PAQUETE ENVIADO");

	PaqueteDatagrama paquete2((char *)num2, 3*sizeof(unsigned int), (char *) "127.0.0.1", 7200);
    printf("Mandando paquete a: %s:%d\n", paquete2.obtieneDireccion(), paquete2.obtienePuerto());
    cliente.envia(paquete2);
    printf("%s\n", "PAQUETE ENVIADO");
    return 0;
}
