#include "Archivo.h"
#include "Semaforo.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <functional>
#include <dirent.h>
#include <list>
#include <regex>
#include <algorithm>
using namespace std;

#define NUM_HILOS 1

DIR *dip;
mutex m;

struct Nodo {
    string palabra;
    int frecuencia;
};

void funcion(int i) {
    string nombre_hilo = "By thread #" + to_string(i) + " ";
    struct dirent *dit;
    string nombre;
    regex regex_palabra("[a-zA-ZáéíóúÁÉÍÓÚñÑüÜ]+");
    list<struct Nodo> lista_palabras;
    while ((dit = readdir(dip)) != NULL) {
        m.lock();
        nombre = dit->d_name;
        m.unlock();
        if (!nombre.compare(".") or !nombre.compare(".."))
            continue;
        
        nombre = "./archivos/" + nombre;
        Archivo original(nombre);
        size_t nbytes = 0;
        
        while((nbytes = original.lee(BUFSIZ)) > 0);
        
        nbytes = 0;
        string palabra;
        list<struct Nodo>::iterator it;
        while (nbytes < original.get_num_bytes()) {
            palabra.append(1, original.get_contenido()[nbytes++]);
            if (!regex_match(palabra, regex_palabra)) {
                palabra = palabra.substr(0, palabra.size()-1);
                if (palabra.size() < 1) {
                    palabra = "";
                    continue;
                }

                transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
                for (it = lista_palabras.begin(); it != lista_palabras.end(); it++) {
                    if (it->palabra == palabra) {
                        it->frecuencia += 1;
                        break;
                    }
                }
                if (it == lista_palabras.end()) {
                    struct Nodo auxiliar;
                    auxiliar.palabra = palabra;
                    auxiliar.frecuencia = 1;
                    lista_palabras.push_back(auxiliar);
                }
                palabra = "";
            }
        }
        for (it = lista_palabras.begin(); it != lista_palabras.end(); it++) {
            cout << "Palabra: " << it->palabra << " frecuencia: " << it->frecuencia << endl;
        }
        //destino.escribe((void *)original.get_contenido(), original.obtiene_num_bytes());
        //destino.escribe((void *)nombre_hilo.c_str(), nombre_hilo.length());

    }
    
}

int main(int argc, char const *argv[]) {
    printf("%s\n", "Inicio");
    
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