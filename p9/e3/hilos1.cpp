#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>
using namespace std;
int global=0;

void funcion1(int valor){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),valor);
	global+=valor;
	sleep(1);
	}

void funcion2(int valor){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),valor);
	global-=valor;
	sleep(1);
	}


int main(int argc, char *argv[]){
	int n;
	if(argc!=2){
		printf("Valor de n=5 \n");
		n=5;
	}
	else{
		n=atoi(argv[1]);
		printf("Valor de n= %d\n",n);
	}

	thread th1(funcion1, n), th2(funcion2, n);
	//cout << "Proceso principal espera que los hilos terminen\n";
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	printf("La variable global: %d\n",global);
	//cout << "El hilo principal termina\n";
	printf("El hilo principal termina\n");
	exit(0);
}
		