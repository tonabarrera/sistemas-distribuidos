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
#include <future>
using namespace std;

#define NUM_HILOS 8

DIR *dip;
mutex m;
struct Nodo {
    string palabra;
    int frecuencia;
};

bool comparar_frecuencias(const struct Nodo a, const struct Nodo b) {
    if (a.frecuencia > b.frecuencia)
        return true;
    return false;
}
void funcion(int i, promise<list<struct Nodo>> *promObj) {
    string nombre_hilo = "taken by thread #" + to_string(i);
    struct dirent *dit;
    string nombre;
    regex regex_palabra("[a-zA-ZáéíóúÁÉÍÓÚñÑüÜ]+");
    list<struct Nodo>::iterator it;
    size_t nbytes = 0;
    string palabra;
    list<struct Nodo> lista_palabras;
    while ((dit = readdir(dip)) != NULL) {
        m.lock();
        nombre = dit->d_name;
        cout << nombre << " "<< nombre_hilo << endl;
        m.unlock();
        if (!nombre.compare(".") or !nombre.compare(".."))
            continue;

        nbytes = 0;
        nombre = "./archivos/" + nombre;
        Archivo original(nombre);
        
        while((nbytes = original.lee(BUFSIZ)) > 0);
        
        nbytes = 0;
        palabra = "";
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
        lista_palabras.sort(comparar_frecuencias);
        lista_palabras.resize(500);
    }
    if (lista_palabras.size() < 1) {
        struct Nodo aux;
        aux.palabra = "NADA";
        aux.frecuencia = 0;
        lista_palabras.push_back(aux);
    }
    promObj->set_value(lista_palabras);
}

int main(int argc, char const *argv[]) {
    printf("%s\n", "Inicio");
    promise<list<struct Nodo>> promiseObj[NUM_HILOS];
    future<list<struct Nodo>> futureObj[NUM_HILOS];
    for (int i = 0; i < NUM_HILOS; i++)
        futureObj[i] = promiseObj[i].get_future(); 
    thread hilos[NUM_HILOS];

    if ((dip = opendir("archivos")) == NULL)
        return -1;

    for (int i = 0; i < NUM_HILOS; ++i)
        hilos[i] = thread(funcion, i, &promiseObj[i]);

    for (int i = 0; i < NUM_HILOS; ++i)
        hilos[i].join();

    if (closedir(dip) == -1)
        return -1;

    list<struct Nodo>::iterator it;
    for (int i = 0; i < NUM_HILOS; i++){
        it = futureObj[i].get().begin();
        cout << it->palabra << " " << it->frecuencia << endl;
    }
    
    /*
    int k = 1;
    list<struct Nodo>::iterator it;
    for (it = lista_palabras.begin(); it != lista_palabras.end(); it++)
        cout << k++ << ".-"<< it->palabra << " - " << it->frecuencia << endl;
    */
    return 0;
}