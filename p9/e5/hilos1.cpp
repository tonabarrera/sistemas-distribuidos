#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include <atomic>
using namespace std;
//atomic<int> global(0);
//int var=0;
int n;
void funcion1(atomic<int>& variable){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),n);
	variable+=n;
	sleep(1);
	}

void funcion2(atomic<int>& variable){

	//cout<<"Hilo " <<this_thread::get_id() << " Valor recibido: " << valor << endl;
	printf("Hilo %ld Valor Recibido: %d\n",this_thread::get_id(),n);
	variable-=n;
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
	atomic<int> var_local(0);

	thread th1(funcion1,ref(var_local)), th2(funcion2,ref(var_local));
	//cout << "Proceso principal espera que los hilos terminen\n";
	printf("Proceso principal espera que los hilos terminen\n");
	th1.join();
	th2.join();
	//printf("La variable global: %d\n",var);
	cout<<"La variable local= "<<var_local<<endl;
	//cout << "El hilo principal termina\n";
	printf("El hilo principal termina\n");
	exit(0);
}

