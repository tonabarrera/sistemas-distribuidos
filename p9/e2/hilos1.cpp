#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;
int var=0;
void funcion1(int valor){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),valor);
	var+=1;
	sleep(1);
	}

void funcion2(int valor){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),valor);
	var-=1;
	sleep(1);
	}

int main(){

	thread th1(funcion1, 1), th2(funcion2, 1);
	//cout << "Proceso principal espera que los hilos terminen\n";
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	printf("La variable global: %d\n",var);
	//cout << "El hilo principal termina\n";
	printf("El hilo principal termina\n");
	exit(0);
}