#include "gfx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <math.h>
#define PI 3.14159265

#define RADIO_MAXIMO 80
#define RADIO_MINIMO 10
using namespace std;

class Asteroide {
public:
    int num_lados; // Numero de lineas del asteroide al menos 5 lados
    double angulo;
    //int direccion_x;
    //int direccion_y;
    int centro_x;
    int centro_y;
    double radio;
    vector<vector<int>> lados;
    vector<vector<int>> vectores;
    vector<vector <double>> matriz_angulos;

    Asteroide();

    Asteroide(int numero, int x, int y, double radio_asteroide){
        num_lados = numero;
        centro_x = x;
        centro_y = y;
        radio = radio_asteroide + 0.0;

        vectores.resize(num_lados);
        lados.resize(num_lados);
        for (int i = 0; i < num_lados; i++){
            lados[i].resize(2);
            vectores[i].resize(2);
        }

        angulo = (double) 360.0/num_lados;
        cout << "Lados: "  << num_lados << endl;
        cout << "Angulo: " << angulo << endl;

        matriz_angulos.resize(2);
        matriz_angulos[0].resize(2);
        matriz_angulos[1].resize(2);

        matriz_angulos[0][0] = cos(10*PI/180);
        matriz_angulos[0][1] = -sin(10*PI/180);
        matriz_angulos[1][0] = sin(10*PI/180);
        matriz_angulos[1][1] = cos(10*PI/180);
    }

    void dibujar() {
        calcular_coordenadas();
        for (int i = 0; i < num_lados; i++){
            lados[i][0] = vectores[i][0] + centro_x;
            lados[i][1] = vectores[i][1] + centro_y;
        }

        for (int i = 0; i < num_lados-1; i++){
            gfx_line(lados[i][0], lados[i][1], lados[i+1][0], lados[i+1][1]);
            //gfx_line(centro_x, centro_y, lados[i][0], lados[i][1]);
        }

        gfx_line(lados[0][0], lados[0][1], lados[num_lados-1][0], lados[num_lados-1][1]);
    }

    void calcular_coordenadas() {
        int *valores_y = new int[2]();
        int *valores_x = new int[2]();

        int magnitud_A = 0;
        int magnitud_B = 0;
        
        int coord_a = 0;
        int coord_b = 0;

        float a = 0;
        float b = 0;
        float c = 0;

        bool comparacion = false;

        magnitud_A = rand() % (int)((radio+10) - (radio) + 1) + (radio);
        magnitud_B = magnitud_A;
        for (int i = 0; i < num_lados-1; i++) {
            //magnitud_B = magnitud_A;
            if (i == 0) {
                coord_a = magnitud_A;
                coord_b = 0;

                vectores[0][0] = coord_a;
                vectores[0][1] = coord_b;
            } else {
                coord_a = vectores[i][0];
                coord_b = vectores[i][1];
            }
                // Genera la mayoria de los errores
                if (coord_a == 0)
                    return;

                a = ((coord_b * coord_b) / (coord_a * coord_a)) + 1;
                b = -(2 * magnitud_A * magnitud_B * coord_b * cos(angulo * PI / 180.0))/(coord_a * coord_a);
                c = magnitud_A * magnitud_B * cos(angulo * PI / 180.0) / coord_a;
                c = c * c;
                c = c - (magnitud_B * magnitud_B);

                // Mas errores
                if (a == 0)
                    return;
                cout << "a="<< a << " b=" << b << " c="<< c << endl;
                cout << "\n";

                resolver_trinomio(a, b, c, valores_y);

                valores_x[0] = ((magnitud_A*magnitud_B*cos(angulo*PI/180))-(coord_b*valores_y[0])) / coord_a;

                valores_x[1] = ((magnitud_A*magnitud_B*cos(angulo*PI/180))-(coord_b*valores_y[1])) / coord_a;

            if (i == 0)
                comparacion = valores_y[0] < valores_y[1];
            else {
                comparacion = comparar_distancias(vectores[i-1][0], vectores[i-1][1], valores_x[0], valores_y[0], valores_x[1], valores_y[1]);
            }

            if (comparacion) {
                vectores[i+1][0] = valores_x[0];
                vectores[i+1][1] = valores_y[0];
            } else {
                vectores[i+1][0] = valores_x[1];
                vectores[i+1][1] = valores_y[1];
            }

            //magnitud_A = magnitud_B;
        }
    }

    void resolver_trinomio(float a, float b, float c, int *valores_y) {
        double dentro = b*b - 4*a*c;
        double raiz = sqrt(dentro);
        int resultado1 = (-b + raiz) / (2*a);
        int resultado2 = (-b - raiz) / (2*a);
        valores_y[0] = resultado1;
        valores_y[1] = resultado2;
    }

    bool comparar_distancias(int centro_x, int centro_y, int x1, int y1, int x2, int y2) {
        double c1 = ((centro_x-x1) * (centro_x-x1)) + ((centro_y-y1) * (centro_y-y1));
        double c2 = ((centro_x-x2) * (centro_x-x2)) + ((centro_y-y2) * (centro_y-y2));

        if (c1 > c2)
            return true;
        return false;
    }

    void rotar() {
        vector<vector <double>> resta;
        
        vector<vector <double>> nuevos_vertices;

        resta.resize(num_lados);
        nuevos_vertices.resize(num_lados);

        for (int i = 0; i < num_lados; i++){
            resta[i].resize(2);
            nuevos_vertices[i].resize(2);

            resta[i][0] = lados[i][0] - centro_x;
            resta[i][1] = lados[i][1] - centro_y;
        }

        for (int i = 0; i < num_lados; i++) {
            for (int j = 0; j < 2; j++) {
                nuevos_vertices[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    nuevos_vertices[i][j] += matriz_angulos[j][k] * resta[i][k];
                }
            }
        }

        for (int i = 0; i < num_lados; i++){
            lados[i][0] = round(nuevos_vertices[i][0] + centro_x);
            lados[i][1] = round(nuevos_vertices[i][1] + centro_y);
        }
        //cout << "vertice: " << lados[0][0] << ", "<< lados[0][1]<< endl;


        
        for (int i = 0; i < num_lados-1; i++){
            gfx_line(lados[i][0], lados[i][1], lados[i+1][0], lados[i+1][1]);
            //gfx_line(centro_x, centro_y, lados[i][0], lados[i][1]);
        }

        gfx_line(lados[0][0], lados[0][1], lados[num_lados-1][0], lados[num_lados-1][1]);
        
    }

    // Mueve el asteroide con base en su radio (tamanio) y la direccion y centro
    void mover_asterioide();
};



int main(int argc, char const *argv[]) {
    srand (time(NULL));
    gfx_open(800, 600, "Animacion de asteroides");
    gfx_color(0, 200, 100);
    gfx_clear();

    vector<Asteroide> asteroides;

    //asteroides.resize(5);

    int radio_random = 10;
    int posicion_x = 0;
    int posicion_y = 0;
    int lados = 5;


    for (int i = 0; i < 5; ++i){
        radio_random = rand() % (RADIO_MAXIMO-RADIO_MINIMO + 1) + RADIO_MINIMO;
        lados = rand() % 3 + 5;
        posicion_y = rand() % (400-20 + 1) + 20;
        posicion_x = rand() % (800-20 + 1) + 20;
        Asteroide aux(lados, posicion_x, posicion_y, radio_random);
        asteroides.push_back(aux);
        asteroides[i].dibujar();
    }

    gfx_flush();
    usleep(100000);
    for(int t = 0; t < 25; t++){
        gfx_clear();
        asteroides[0].rotar();
        asteroides[1].rotar();
        asteroides[2].rotar();
        asteroides[3].rotar();
        asteroides[4].rotar();

        gfx_flush();
        usleep(100000); //24 por segundo
    }
    /*
    char c;
    while(1) {
        // Wait for the user to press a character.
        c = gfx_wait();
        gfx_flush();
        // Quit if it is the letter q.
        if(c == 'q') break;
    }
    */
    return 0;
}