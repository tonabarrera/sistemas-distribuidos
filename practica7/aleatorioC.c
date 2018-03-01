#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("%s\n", "Ingresa el numero de cadenas a concatenar");
        return -1;
    }
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    char *cadenota2 = NULL;

    unsigned long N = atol(argv[1]);
    int tam = sizeof(char)*5;
    char *palabra = (char*) malloc(sizeof(char)*4);
    char *cadenota = NULL;
    int cantidad = 0;
    start = clock();
    for (unsigned long i = 0; i < N; i++) {
        cadenota = (char*) realloc(cadenota, tam*(i+1));
        palabra[0] = rand() % 25 + 65;
        palabra[1] = rand() % 25 + 65;
        palabra[2] = rand() % 25 + 65;
        palabra[3] = ' ';
        strcat(cadenota, palabra);
    }
    cadenota2 = cadenota;
    while ((cadenota = strstr(cadenota, "IPN")) != NULL){
        cantidad++;
        cadenota = cadenota+3;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s %f\n", cadenota2, cpu_time_used);
    printf("N=%lu IPN encontrados=%d\n", N, cantidad);
    return 0;
}