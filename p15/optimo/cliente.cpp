#include "Solicitud.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){
    Solicitud cliente;
    if(argc<3)
        printf("indicar IP y puerto del servidor\n");
    
    int ordenaCadena=1;
    char cadena[]="Yo caminare entre las piedras hasta sentir el temblor en mis piernas a veces tengo temor lo se a veces verguenza";
    auto start = high_resolution_clock::now();
    for(int i = 0; i < 100000; i++)
        cliente.doOperation(argv[1], atoi(argv[2]),ordenaCadena, cadena);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("%s %ld %s\n", "Tiempo:", duration.count(), " microsegundos");
    return 0;
}