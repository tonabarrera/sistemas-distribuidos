#include "Archivo.h"
int main(int argc, char const *argv[]) {
    /*if(argc != 3) {
        printf("Forma de uso: %s archivo_origen archivo_destino\n", argv[0]);
        return -1;
    }*/
    Archivo original("origen.txt");
    Archivo destino("destino.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
    size_t nbytes = 0;
    while((nbytes = original.lee(20)) > 0)
        destino.escribe((void *)original.get_contenido(), nbytes);
    
    return 0;
}