#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;
PoligonoIrreg::PoligonoIrreg(){}

bool PoligonoIrreg::comparacion(Coordenada a, Coordenada b) {
    if (a.get_magnitud() < b.get_magnitud())
        return true;
    return false;
}

void PoligonoIrreg::anadeVertice(Coordenada c) {
    vertices.push_back(c);
}

void PoligonoIrreg::imprimeVertices() {
    cout << "Vértices: \n";
    for(int i=0; i<vertices.size(); i++){
        cout << "(" << vertices[i].obtenerX() <<", " << vertices[i].obtenerY() << ") = " << vertices[i].get_magnitud() << endl;
    }
}
void PoligonoIrreg::ordenarVertices() {
    sort(vertices.begin(), vertices.end(), comparacion);
}


