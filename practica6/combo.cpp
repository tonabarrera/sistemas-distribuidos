#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

int main(){
    PoligonoIrreg p;


    p.anadeVertice(Coordenada(5,6));
    p.anadeVertice(Coordenada(1,2));
    //p.imprimeVertices();
    
    p.imprimeVertices();
    p.ordenarVertices();
    cout << "Despues de ordenar" << endl;
    p.imprimeVertices();

    
    return 0;
}
