#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    struct Operandos operandos;

    if (argc < 3) {
        printf("%s\n", "Faltan parametros");
        return -1;
    }

    operandos.i = atoi(argv[1]);
    operandos.j = atoi(argv[2]);

    printf("%d + %d = %f \n", operandos.i, operandos.j, suma(operandos));
    printf("%d * %d = %f \n", operandos.i, operandos.j, producto(operandos));
    printf("%d / %d = %f \n", operandos.i, operandos.j, cociente(operandos));

    return 0;
}