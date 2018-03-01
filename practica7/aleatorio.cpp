#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("%s\n", "Ingresa el numero de cadenas a concatenar");
        return -1;
    }
    unsigned long N = atol(argv[1]);
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));

    char *palabra = (char*) malloc(sizeof(char)*4);
    int cantidad = 0;
    string cadenota;
    start = clock();
    for (unsigned long i = 0; i < N; i++) {
        palabra[0] = rand() % 25 + 65;
        palabra[1] = rand() % 25 + 65;
        palabra[2] = rand() % 25 + 65;
        palabra[3] = ' ';
        cadenota.append(palabra);
    }
    size_t pos = 0;
    while ((pos = cadenota.find("IPN", pos)) != string::npos){
        cantidad++;
        pos += 3;
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << cadenota << " " << cpu_time_used << endl;
    cout << "N=" << N << " IPN encontrados= " << cantidad << endl;
    return 0;
}