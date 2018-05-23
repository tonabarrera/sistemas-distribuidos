#include "Archivo.h"
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

struct Nodo {
    string palabra;
    unsigned int frecuencia;
};

DIR *dip;
mutex m;

bool comparar_frecuencias(const struct Nodo a, const struct Nodo b) {
    if (a.frecuencia > b.frecuencia)
        return true;
    return false;
}

void funcion(const char *carpeta, promise<list<struct Nodo>> *promObj) {
    struct dirent *dit;
    struct Nodo auxiliar;
    auxiliar.frecuencia = 1;
    string nombre;
    regex regex_palabra("[a-zA-ZáéíóúÁÉÍÓÚñÑüÜ]+");
    list<struct Nodo>::iterator it;
    size_t nbytes = 0;
    string palabra;
    list<struct Nodo> lista_palabras;
    m.lock();
    dit = readdir(dip);
    m.unlock();
    while (dit != NULL) {
        nombre = dit->d_name;
        m.lock();
        dit = readdir(dip);
        m.unlock();
        if (!nombre.compare(".") or !nombre.compare(".."))
            continue;

        nbytes = 0;
        nombre = "/" + nombre;
        nombre = carpeta + nombre;
        Archivo original(nombre);
        
        while((nbytes = original.lee(BUFSIZ)) > 0);
        
        nbytes = 0;
        palabra = "";
        while (nbytes < original.get_num_bytes()) {
            palabra.append(1, original.get_contenido()[nbytes++]);
            if (!regex_match(palabra, regex_palabra)) {
                palabra = palabra.substr(0, palabra.size() - 1);
                if (palabra.size() < 1) {
                    palabra = "";
                    continue;
                }
                transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
                for (it = lista_palabras.begin(); it != lista_palabras.end(); it++) {
                    if (!(it->palabra.compare(palabra))) {
                        it->frecuencia += 1;
                        break;
                    }
                }
                if (it == lista_palabras.end()) {
                    auxiliar.palabra = palabra;
                    lista_palabras.push_back(auxiliar);
                }
                palabra = "";
            }
        }
        lista_palabras.sort(comparar_frecuencias);
        
        if (lista_palabras.size() > 10000)
            lista_palabras.resize(10000);
    }
    if (lista_palabras.size() < 1) {
        auxiliar.palabra = "NADA";
        auxiliar.frecuencia = 0;
        lista_palabras.push_back(auxiliar);
    }
    promObj->set_value(lista_palabras);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("%s\n", "Faltan parametros");
        printf("%s\n", "./principal <numero-hilos> <nombre carpeta>");
        return -1;
    }
    short numero_hilos = atoi(argv[1]);
    if (numero_hilos > 8) {
        printf("%s\n", "El numero máximo de hilos es 8");
        return -1;
    }

    promise<list<struct Nodo>> promiseObj[numero_hilos];
    future<list<struct Nodo>> futureObj[numero_hilos];
    thread hilos[numero_hilos];
    unsigned short i = 0;
    
    for (i = 0; i < numero_hilos; i++)
        futureObj[i] = promiseObj[i].get_future(); 

    if ((dip = opendir(argv[2])) == NULL){
        printf("%s %s\n", "Error al abrir la carpeta:", argv[2]);
        return -1;
    }

    for (i = 0; i < numero_hilos; i++)
        hilos[i] = thread(funcion, argv[2], &promiseObj[i]);

    for (i = 0; i < numero_hilos; i++)
        hilos[i].join();

    if (closedir(dip) == -1)
        return -1;

    list<struct Nodo>::iterator it;
    list<struct Nodo>::iterator it2;
    list<struct Nodo> lista_final;
    list<struct Nodo> resultados[numero_hilos];

    for (i = 0; i < numero_hilos; i++)
        resultados[i] = futureObj[i].get();

    for (i = 0; i < numero_hilos; i++) {
        for (it = resultados[i].begin(); it != resultados[i].end(); it++) {
            for (it2 = lista_final.begin(); it2 != lista_final.end(); it2++) {
                if (it2->palabra.compare(it->palabra) == 0) {
                    it2->frecuencia += it->frecuencia;
                    break;
                }
            }
            if (it2 == lista_final.end())
                lista_final.push_back(*it);
        }
        lista_final.sort(comparar_frecuencias);
    }

    lista_final.resize(500);
    i = 1;
    for (it = lista_final.begin(); it != lista_final.end(); it++)
        cout << i++ << ".- " << it->palabra << " " << it->frecuencia << endl;
    
    return 0;
}