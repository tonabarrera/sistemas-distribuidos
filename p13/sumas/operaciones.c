#include "operaciones.h"

struct Operandos suma(struct Operandos o) {
    return o.i + o.j;
}

struct Operandos producto(struct Operandos o) {
    return o.i * o.j;
}

struct Operandos cociente(struct Operandos o) {
    return o.i / (float) o.j;
}