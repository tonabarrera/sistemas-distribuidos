#include "PoligonoIrreg.h"
#include <iostream>
#include<stdlib.h>
#include <time.h> 

using namespace std;

double fRand(double fMin = -100, double fMax = 100){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(){
	srand (time(NULL)); //Inicializa random
	
	int n = 10;
	PoligonoIrreg p(n);
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(3);
	
	for(int i=0; i<n; i++){
		p.anadeVertice(Coordenada(fRand(),fRand()));
	}
	
	p.imprimeVertices();
    p.ordenarVertices();
    cout << "Despues de ordenar" << endl;
    p.imprimeVertices();
	
	
	return 0;
}




