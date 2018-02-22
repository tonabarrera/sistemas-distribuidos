#include "Coordenada.h"

//Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {}

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {
    y = xx * sin(yy * PI / 180);
    x = xx * cos(yy * PI / 180);
}

double Coordenada::obtenerX() {
    return x;
}

double Coordenada::obtenerY() {
    return y;
}