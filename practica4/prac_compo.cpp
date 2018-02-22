#include "Rectangulo.h"

int main(int argc, char const *argv[]) {
    // 2 3 y 5 1
    Rectangulo rectangulo1(Coordenada(3.61, 56.31), Coordenada(5.1, 11.31));
    double ancho, alto;
    cout << "Calculando el area de un rectangulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();

    cout << "El area del rectangulo es = " << rectangulo1.obtenerArea() << endl;
    return 0;
}