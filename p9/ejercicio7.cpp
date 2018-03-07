#include <iostream>
#include <unistd.h>
#include <thread>
#include "Semaforo.h"
#define n 10

using namespace std;

int global = 10;
Semaforo sem1, sem2;
void funcion1() {
    while(global > 0){
        sem1.wait();
        printf("Soy el hilo 1, y esta es la impresion %d\n", global--);
        sem2.post();
    }
}

void funcion2() {
    while(global > 0){
        sem2.wait();
        printf("Soy el hilo 2, y esta es la impresion %d\n", global--);
        sem1.post();
    }
}

int main(){
    //Inicializa los semaforos
    printf("%ld\n", sizeof(int));
    sem1.init(1);
    sem2.init(0);
    thread th1(funcion1), th2(funcion2);
    th1.join();
    th2.join();
    exit(0);
}