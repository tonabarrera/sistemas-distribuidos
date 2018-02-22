#ifndef __RECTANGULO_H_
#define __RECTANGULO_H_
#include "Coordenada.h"
#include <iostream>

using namespace std;

class Rectangulo {
private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
public:
    Rectangulo();
    Rectangulo(Coordenada, Coordenada);
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
    double obtenerArea();
};

#endif