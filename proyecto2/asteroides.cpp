#include "gfx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

class Asteroide {
public:
    int num_lados = 6; // Numero de lineas del asteroide al menos 5 lados
    int direccion_x;
    int direccion_y;
    int centro_x;
    int centro_y;
    int radio;
    int radio_interno = 100;
    vector<vector<int>> lados;
    // Recuperar la mayoria de parametros
    Asteroide(int numero, int x, int y, int radio_externo){
        // Inicializar el vector de lados
        /*
        num_lados = numero;
        centro_x = x;
        centro_y = y;
        radio = radio_externo;
        radio_interno = radio / 2;
        lados.resize(num_lados);
        for (int i = 0; i < num_lados; i++)
            lados[i].resize(2);
        */
    }

    void dibujar_asteroide();
    void calcular() {
        int angulo = 360/num_lados;
        int magnitud_A = rand() % radio_interno + radio_interno;
        int magnitud_B = rand() % radio_interno + radio_interno;
        int coord_a = centro_x + magnitud_A;
        int coord_b = centro_y;

        float a = ((coord_b*coord_b)/(coord_a*coord_a))+1;
        float b = -(2*magnitud_A*magnitud_B*coord_b*cos(angulo*PI/180.0))/(coord_a*coord_a);
        float c = magnitud_A * magnitud_B * cos(angulo*PI/180.0) / coord_a;
        c = c*c;
        c = c - (magnitud_B*magnitud_B);
        formula_general(a, b, c);
    }
    // Calcula los lados con base en el centro, radio y numero de lados
    void formula_general(float a, float b, float c);
    // Mueve el asteroide con base en su radio (tamanio) y la direccion y centro
    void mover_asterioide();
};

void Asteroide::formula_general(float a, float b, float c) {
    cout << a << " " << b << " " <<c << endl;
    double dentro = (b*b) - 4*a*c;
    double raiz = sqrt(dentro);
    int resultado1 = (-b + raiz) / (2*a);
    int resultado2 = (-b - raiz) / (2*a);
    cout << resultado1 << " " << resultado2;
    return;
}

int main(int argc, char const *argv[]) {
    srand (time(NULL));
    gfx_open(800, 600, "Animacion de asteroides");
    gfx_color(0, 200, 100);
    gfx_clear();
    Asteroide as(5, 200, 200, 100);
    as.calcular();
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