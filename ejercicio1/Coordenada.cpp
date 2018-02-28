#include "Coordenada.h"
#include <iostream>
#include "math.h"
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {
    magnitud = sqrt(x*x + y*y);
}

double Coordenada::obtenerX() {
    return x;
}

double Coordenada::obtenerY() {
    return y;
}

double Coordenada::get_magnitud() {
    return magnitud;
}