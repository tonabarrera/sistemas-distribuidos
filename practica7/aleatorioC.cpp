#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("%s\n", "Ingresa el numero de cadenas a concatenar");
        return -1;
    }
    srand(time(NULL));

    int N = atoi(argv[1]);
    int tam = sizeof(char)*4;
    char *palabra = (char*)malloc(tam);
    char *cadenota = NULL;
    for (int i = 0; i < N; i++) {
        cadenota = (char*) realloc(cadenota, tam*(i+1));
        for (int j = 0; j<3; j++){
            palabra[j] = rand() % 25 + 65;
        }
        palabra[3] = ' ';
        memcpy(cadenota+(i*4), palabra, tam);
    }
    printf("%s\n", cadenota);
    return 0;
}