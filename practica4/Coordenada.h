#ifndef __COORDENADA_H_
#define __COORDENADA_H_

#include <math.h>
#define PI 3.14159

class Coordenada{
private:
    double x;
    double y;
public:
    Coordenada(double=0, double=0);
    double obtenerX();
    double obtenerY();
};

#endif