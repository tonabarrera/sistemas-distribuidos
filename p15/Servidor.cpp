#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <resolv.h>
#include "paquetedatagrama.hpp"
#include "socketdatagrama.hpp"
#include <vector>
#include <math.h>
#include <time.h>
#include <inttypes.h>
using namespace std;

struct messageSC{
   char nombre[45]; //Nombre del alumno con fin de cadena incluido
   char temporal[101]; //Cadena temporal con fin de cadena incluido
   uint32_t num; //Numero entero que se multiplica por 10E-4
};


int main(int argc, char*argv[])
{
	int i = 0;
	char caracteres[100];
	messageSC *datos = new messageSC;
	memcpy(datos->nombre, "Edson Gonzalez Tinajero\0", sizeof(datos->nombre));
    int x=0,y=0;
    float suma=0;
    uint32_t promedio = 0;


    while(true){
        SocketDatagrama server(7300);
        PaqueteDatagrama request(sizeof(caracteres));
        server.recibe(request);
        memcpy(caracteres, request.obtieneDatos(), sizeof(caracteres));
        cout << "Arreglo: " << caracteres << endl;
        x=0;
        for(int i=0; i<=100; i++){
        	datos -> temporal[i] = 0;
        	if(caracteres[i]>=65 && caracteres[i]<=90){
        		datos -> temporal[x] = caracteres[i];
        		suma=suma+caracteres[i];
        		x++;
        	}else if(caracteres[i]>=97 && caracteres[i]<=122){
        		datos -> temporal[x] = caracteres[i];
        		suma=suma+caracteres[i];
        		x++;
        	}
        }
        datos -> temporal[101] = 0; 
        cout << "DEBUG" << endl;
        cout << datos -> temporal << endl;
        promedio = suma/x;
        promedio = (float)promedio * 10 * 10 * 10 * 10;
        cout<<promedio<<endl;
        datos -> num = promedio;
        SocketDatagrama cliente(0);
        PaqueteDatagrama datosEnviar((char*)datos,sizeof(messageSC), request.obtieneDireccion(), request.obtienePuerto());
        cliente.envia(datosEnviar);
    }

    return 0;
}
