#include "Archivo.h"

Archivo::Archivo(string filename) {
    num_bytes = 0;
    nombre_archivo = filename;
    fd = open(nombre_archivo.c_str(), O_RDONLY);
}

Archivo::Archivo(string filename, int banderas, mode_t modo) {
    num_bytes = 0;
    nombre_archivo = filename;
    fd = open(nombre_archivo.c_str(), banderas, modo);
}

size_t Archivo::lee(size_t nbytes) {
    char auxiliar[nbytes];
    int n = read(fd, auxiliar, sizeof(auxiliar));
    num_bytes += n;
    contenido = (char*) realloc(contenido, num_bytes);
    memcpy(contenido+(num_bytes-n), auxiliar, n);

    return n;
}

size_t Archivo::escribe(void *buffer, size_t nbytes) {
    buffer = buffer+num_bytes;
    size_t bytes = write(fd, buffer, nbytes);
    num_bytes += bytes;
    return bytes;
}

const char* Archivo::get_contenido() {
    return contenido;
}

Archivo::~Archivo() {
    delete contenido;
    //free(contenido);
    close(fd);
}


