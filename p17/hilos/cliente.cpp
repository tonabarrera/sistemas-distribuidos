#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "PaqueteDatagrama.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

SocketDatagrama socketlocal(0);


void escuchar() {
    short i = 0;
    while(true) {
        PaqueteDatagrama respuesta(sizeof(struct mensaje));
        printf("%d .- %s\n", i++, "Escuchando...");
        socketlocal.recibe(respuesta);
        printf("********** Encontre a : %s **********\n", respuesta.obtieneDireccion());
    }
}
// 10.100.0.0
void buscar() {
    string direccion = "10.100.";
    short i = 70;
    short j = 0;
    string temp;

    char cadena[]="Yo caminare entre las piedras hasta sentir el temblor en mis piernas a veces tengo temor lo se a veces verguenza";

    struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
    msj->messageType = 0;
    msj->requestId = 1;
    memcpy(msj->IP, direccion.c_str(), strlen(direccion.c_str()));
    msj->puerto = 7200;
    msj->operationId = 1;
    memcpy(msj->arguments, cadena, strlen(cadena));

    PaqueteDatagrama solicitud(sizeof(struct mensaje));
    solicitud.inicializaPuerto(7200);
    solicitud.inicializaDatos((char *)msj);

    while (i < 256) {
        temp = direccion + to_string(i) + "." + to_string(j);
        
        printf("%s %s\n", "Solicitud a: ", temp.c_str());

        solicitud.inicializaIp((char *) temp.c_str());
        socketlocal.envia(solicitud);

        if (++j > 255){
            j = 0;
            i++;
        }
    }
}


int main(int argc, char *argv[]){
    //int ordenaCadena=1;
    //char cadena[]="Yo caminare entre las piedras hasta sentir el temblor en mis piernas a veces tengo temor lo se a veces verguenza";
    
    auto start = high_resolution_clock::now();
    /*
    for(int i = 0; i < 100000; i++)
        cliente.doOperation(argv[1], atoi(argv[2]), ordenaCadena, cadena);
    */

    thread busqueda(buscar);
    //thread recepcion(escuchar);
    busqueda.join();
    //recepcion.join();

    printf("%s\n", "TERMINO");

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("%s %ld %s\n", "Tiempo:", duration.count(), " microsegundos");
    return 0;
}