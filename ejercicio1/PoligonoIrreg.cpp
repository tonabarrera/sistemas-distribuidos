#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <algorithm>
using namespace std;
PoligonoIrreg::PoligonoIrreg(int n){	
	vertices.reserve(n);
} 

bool PoligonoIrreg::comparacion(Coordenada a, Coordenada b) {
    return a.get_magnitud() < b.get_magnitud();
}

void PoligonoIrreg::anadeVertice(Coordenada c) {
    vertices.push_back(c);
}

void PoligonoIrreg::imprimeVertices() {
	cout << "Vértices: \n";
	for(int i=0; i<vertices.size(); i++){
		cout << "(" << vertices[i].obtenerX() <<", " << vertices[i].obtenerY() << "), distancia al origen: "<< vertices[i].get_magnitud() <<"\n";
	}
}

void PoligonoIrreg::ordenarVertices() {
    sort(vertices.begin(), vertices.end(), comparacion);
}


