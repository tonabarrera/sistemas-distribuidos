#include "gfx.h"
#include <stdio.h>
#include <unistd.h>
#include <vector>
using namespace std;

class Asteroide {
public:
    int num_lados; // Numero de lineas del asteroide al menos 5 lados
    int direccion_x;
    int direccion_y;
    int centro_x;
    int centro_y;
    int radio;
    vector<vector<int>> lados;
    // Recuperar la mayoria de parametros
    Asteroide(int num_lados){
        // Inicializar el vector de lados
        lados.resize(num_lados);
        for (int i = 0; i < num_lados; i++)
            lados[i].resize(2);

        lados[0][0] = 10;
        lados[0][1] = 15;
    }

    void dibujar_asteroide() {
        gfx_line(lados[0][0], lados[0][1], 45, 15);
        gfx_line(10, 15, 10, 50);
        gfx_line(10, 50, 30, 70);
    }
    // Calcula los lados con base en el centro, radio y numero de lados
    void calcular_lados();
    // Mueve el asteroide con base en su radio (tamanio) y la direccion y centro
    void mover_asterioide();
};

int main(int argc, char const *argv[]) {
    gfx_open(800, 600, "Animacion de asteroides");
    gfx_color(0, 200, 100);
    gfx_clear();
    Asteroide as(3);
    as.dibujar_asteroide();
    gfx_flush();
    char c;
    while(1) {
        // Wait for the user to press a character.
        c = gfx_wait();

        // Quit if it is the letter q.
        if(c == 'q') break;
    }
    return 0;
}