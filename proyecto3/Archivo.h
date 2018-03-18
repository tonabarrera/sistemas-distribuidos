#ifndef __ARCHIVO__
#define __ARCHIVO__

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

class Archivo {
private:
    string nombre_archivo;
    int fd;
    char *contenido;
    size_t num_bytes;
public:
    Archivo(string filename);
    Archivo(string filename, int banderas, mode_t modo);
    size_t lee(size_t nbytes);
    size_t escribe(void *buffer, size_t nbytes);
    size_t obtiene_num_bytes();
    const char *get_contenido();
    ~Archivo();
};

#endif