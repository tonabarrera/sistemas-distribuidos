#include "Rectangulo.h"

Rectangulo::Rectangulo(void) : superiorIzq(0, 0), inferiorDer(0, 0) {}

Rectangulo::Rectangulo(Coordenada superior, Coordenada inferior):superiorIzq(superior), inferiorDer(inferior) {}

void Rectangulo::imprimeEsq(void) {
    cout << "Para la esquina esquina superior izquierda.\n";
    cout << "x=" << superiorIzq.obtenerX() << " y=" << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha \n";
    cout << "x= " << inferiorDer.obtenerX() << " y=" << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq(void) {
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(void) {
    return inferiorDer;
}

double Rectangulo::obtenerArea(void) {
    double alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    double ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    return alto * ancho;
}