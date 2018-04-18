#include "operaciones.h"

double suma(struct Operandos o) {
    return o.i + o.j;
}
double producto(struct Operandos o) {
    return o.i * o.j;
}

double cociente(struct Operandos o) {
    return o.i / (float) o.j;
}