#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;
PoligonoIrreg::PoligonoIrreg(){}


void PoligonoIrreg::anadeVertice(Coordenada c) {
    vertices.push_back(c);
}

void PoligonoIrreg::imprimeVertices() {
	cout << "Vértices: \n";
	for(int i=0; i<vertices.size(); i++){
		cout << "(" << vertices[i].obtenerX() <<", " << vertices[i].obtenerY() << ")\n";
	}
}


