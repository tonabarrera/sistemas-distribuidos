#include "gfx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <math.h>

#define PI 3.14159265

#define RADIO_MAXIMO 100
#define RADIO_MINIMO 10

#define MIN_NUM_LADOS 6
#define MAX_NUM_LADOS 10

#define LARGO_VENTANA 800
#define ANCHO_VENTANA 495

#define MAX_VELOCIDAD 10
#define MIN_VELOCIDAD 1

using namespace std;

class Asteroide {
private:
    int num_lados;
    double vel_angular;
    double velocidad;
    int *direccion = new int[2]();
    int *centro = new int[2]();
    double radio;
    vector<vector<int>> vertices;
    vector<vector <double>> matriz_rotacion;

public:
    Asteroide(int numero, int x, int y, double radio_asteroide){
        num_lados = numero;
        centro[0] = x;
        centro[1] = y;
        radio = radio_asteroide;

        calcular_variables();
        inicializar_matriz_rotacion();
    }

    void calcular_variables(void) {
        vertices.resize(num_lados);
        for (int i = 0; i < num_lados; i++)
            vertices[i].resize(2);

        velocidad = (-0.1*radio) + 11.0;

        direccion[0] = rand() % (MAX_VELOCIDAD - MIN_VELOCIDAD + 1) + MIN_VELOCIDAD;
        direccion[1] = (velocidad*velocidad) - (direccion[0]*direccion[0]);
        direccion[1] = round(sqrt(direccion[1]));
        if (rand() % 2)
            direccion[0] *= -1;
        if (rand() % 2)
            direccion[1] *= -1;

        vel_angular = -0.21*radio + 22.14;
        if (rand() % 2)
            vel_angular *= -1;

        return;
    }

    void set_centro(int x, int y) {
        centro[0] = x;
        centro[1] = y;
    }

    void set_radio(int r) {
        radio = r;
    }

    void set_lados(int l) {
        num_lados = l;
    }

    void inicializar_matriz_rotacion(void) {
        matriz_rotacion.resize(2);
        matriz_rotacion[0].resize(2);
        matriz_rotacion[1].resize(2);

        matriz_rotacion[0][0] = cos(vel_angular*PI/180);
        matriz_rotacion[0][1] = -sin(vel_angular*PI/180);
        matriz_rotacion[1][0] = sin(vel_angular*PI/180);
        matriz_rotacion[1][1] = cos(vel_angular*PI/180);

        return;
    }

    void dibujar(void) {
        int i = 0;
        for (; i < num_lados-1; i++)
            gfx_line(vertices[i][0], vertices[i][1], vertices[i+1][0], vertices[i+1][1]);
        
        gfx_line(vertices[0][0], vertices[0][1], vertices[i][0], vertices[i][1]);

        return;
    }

    void calcular_coordenadas(void) {
        double angulo1 = 0;
        double angulo2 = 0;
        for (int i = 0; i < num_lados-1; i++) {
            angulo1 = i * (2*PI/num_lados);
            angulo2 = (i+1) * (2*PI/num_lados);

            vertices[i][0] = centro[0] + radio*cos(angulo1) + calcular_diferencia();
            vertices[i][1] = centro[1] + radio*sin(angulo1) + calcular_diferencia();
            vertices[i+1][0] = centro[0] + radio*cos(angulo2) + calcular_diferencia();
            vertices[i+1][1] = centro[1] + radio*sin(angulo2) + calcular_diferencia();
        }
        return;
    }

    int calcular_diferencia(void) {
        int valor = 3;
        if (radio > 70)
            valor = 15;
        else if (radio > 40)
            valor = 10; 
        valor = rand() % valor + 1;
        if (rand() % 2)
            return valor*-1;
        return valor;
    }

    void rotar(void) {
        vector<vector <double>> resta;
        vector<vector <double>> nuevos_vertices;
        int i = 0;
        int j = 0;
        int k = 0;

        resta.resize(num_lados);
        nuevos_vertices.resize(num_lados);

        for (i = 0; i < num_lados; i++){
            resta[i].resize(2);
            nuevos_vertices[i].resize(2);

            resta[i][0] = vertices[i][0] - centro[0];
            resta[i][1] = vertices[i][1] - centro[1];
        }

        for (i = 0; i < num_lados; i++)
            for (j = 0; j < 2; j++) {
                nuevos_vertices[i][j] = 0;
                for (k = 0; k < 2; k++)
                    nuevos_vertices[i][j] += matriz_rotacion[j][k] * resta[i][k];
            }

        for (i = 0; i < num_lados; i++){
            vertices[i][0] = round(nuevos_vertices[i][0] + centro[0]);
            vertices[i][1] = round(nuevos_vertices[i][1] + centro[1]);
        }

        dibujar();

        return;
    }

    bool mover(void) {
        centro[0] += direccion[0];
        centro[1] += direccion[1];

        if (centro[0]>LARGO_VENTANA || centro[0]<0 || centro[1]<0 || centro[1]>ANCHO_VENTANA)
            return true;

        for (int i = 0; i < num_lados; i++) {
            vertices[i][0] += direccion[0];
            vertices[i][1] += direccion[1];
        }

        dibujar();

        return false;
    }
};


class Controlador {
private:
    int numero;
    int radio_random = 10;
    int posicion_x = 0;
    int posicion_y = 0;
    int lados = 5;
    vector<Asteroide> asteroides;

    void llenar_vector(void) {
        for (int i = 0; i < numero; i++){
            generar_valores();
            Asteroide aux(lados, posicion_x, posicion_y, radio_random);
            asteroides.push_back(aux);
            asteroides[i].calcular_coordenadas();
            asteroides[i].dibujar();
        }
        gfx_flush();
        usleep(50000);

        return;
    }

    void generar_valores(void) {
        radio_random = rand() % (RADIO_MAXIMO - RADIO_MINIMO + 1) + RADIO_MINIMO;
        lados = rand() % (MAX_NUM_LADOS - MIN_NUM_LADOS + 1) + MIN_NUM_LADOS;
        if (rand() % 2) {
            posicion_y = rand() % (ANCHO_VENTANA - 5 + 1) + 5;
            if (posicion_y > 50 || posicion_y < (ANCHO_VENTANA-50))
                if (rand() % 2)
                    posicion_x = 0;
                else
                    posicion_x = LARGO_VENTANA;
            else
                posicion_x = rand() % (LARGO_VENTANA-5 + 1) + 5;
        } else {
            posicion_x = rand() % (LARGO_VENTANA-5 + 1) + 5;
            if (posicion_x > 50 || posicion_x < (LARGO_VENTANA-50))
                if (rand() % 2)
                    posicion_y = 0;
                else
                    posicion_y = ANCHO_VENTANA;
            else
                posicion_y = rand() % (ANCHO_VENTANA - 5 + 1) + 5;
        }
        
        return;
    }

public:
    Controlador(int num) {
        numero = num;
        asteroides.reserve(numero);
        srand (time(NULL));
        gfx_open(LARGO_VENTANA, ANCHO_VENTANA, "Animacion de asteroides");
        gfx_color(0, 200, 100);
        gfx_clear();
    }

    void iniciar_animacion(void) {
        llenar_vector();
        int i = 0;
        while(true) {
            for (i = 0; i < numero; i++)
                if (asteroides[i].mover()) {
                    generar_valores();
                    asteroides[i].set_centro(posicion_x, posicion_y);
                    asteroides[i].set_radio(radio_random);
                    asteroides[i].set_lados(lados);
                    asteroides[i].calcular_variables();
                    asteroides[i].inicializar_matriz_rotacion();
                    asteroides[i].calcular_coordenadas();
                }
            gfx_flush();
            gfx_clear();
            
            for (i = 0; i < numero; i++)
                asteroides[i].rotar();
            gfx_clear();    
            usleep(50000);
            if(gfx_event_waiting()) break;
        }

        return;
    }

};

int main(int argc, char const *argv[]) {
    if (argc < 2){
        printf("Olvidaste poner el numero de asteroides\n");
        return -1;
    }

    Controlador controlador(atoi(argv[1]));
    controlador.iniciar_animacion();
    
    return 0;
}