#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if (argc < 2){
        printf("%s\n", "Olvidaste ingresar un valor");
        return -1;
    }
    double i = 1;
    double seno = 0;
    double coseno = 0;
    double tangente = 0;
    double logaritmo = 0;
    double raiz = 0;
    double max = atof(argv[1]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    while(i<max) {
        seno += sin(i);
        coseno += cos(i);
        tangente += tan(i);
        logaritmo += log10(i);
        raiz += sqrt(i);
        i++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo %f max=%f\n", cpu_time_used, max);
    return 0;
}