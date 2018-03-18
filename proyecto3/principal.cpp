#include "Archivo.h"
#include "Semaforo.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <dirent.h>
using namespace std;

#define NUM_HILOS 1

DIR *dip;
mutex m;

void funcion(int i) {
    string nombre_hilo = "By thread #" + to_string(i) + " ";
    struct dirent *dit;
    string nombre;
    while ((dit = readdir(dip)) != NULL) {
        m.lock();
        nombre = dit->d_name;
        m.unlock();
        if (!nombre.compare(".") or !nombre.compare(".."))
            continue;
        
        string dest_nombre = "destino_" + nombre;
        nombre = "./archivos/" + nombre;
        Archivo original(nombre);
        Archivo destino(dest_nombre, O_WRONLY|O_TRUNC|O_CREAT, 0666);
        size_t nbytes = 0;
        
        while((nbytes = original.lee(BUFSIZ)) > 0);
        destino.escribe((void *)original.get_contenido(), original.obtiene_num_bytes());
        destino.escribe((void *)nombre_hilo.c_str(), nombre_hilo.length());

    }
    
}

int main(int argc, char const *argv[]) {
    printf("%s\n", "Iniciando los hilos");
    thread hilos[NUM_HILOS];

    if ((dip = opendir("archivos")) == NULL)
        return -1;

    for (int i = 0; i < NUM_HILOS; ++i)
        hilos[i] = thread(funcion, i);

    for (int i = 0; i < NUM_HILOS; ++i)
        hilos[i].join();

    if (closedir(dip) == -1)
        return -1;

    return 0;
}