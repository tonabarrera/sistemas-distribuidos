#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include <atomic>
using namespace std;
atomic<int> global(0);
int var=0;
int n;
void funcion(int valor){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),valor);
	sleep(2);
	}

void ChangeVal(int valor){
	switch(valor){
		case 5: global+=n;
		break;

		case 10: global-=n;
		break;
	}
	sleep(1);

}

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Valor de n=5 \n");
		n=5;
	}
	else{
		n=atoi(argv[1]);
		printf("Valor de n= %d\n",n);
	}

	thread th1(ChangeVal, 5), th2(ChangeVal, 10);
	//cout << "Proceso principal espera que los hilos terminen\n";
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	//printf("La variable global: %d\n",var);
	cout<<"La variable global= "<<global<<endl;
	//cout << "El hilo principal termina\n";
	printf("El hilo principal termina\n");
	exit(0);
}

