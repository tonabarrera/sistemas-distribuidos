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
    /* FORMA NO TAN CHEVERE
    char auxiliar[nbytes];
    int n = read(fd, auxiliar, sizeof(auxiliar));
    num_bytes += n;
    contenido = (char*) realloc(contenido, num_bytes);
    memcpy(contenido+(num_bytes-n), auxiliar, n);
    */
    contenido = (char*) realloc(contenido, num_bytes+nbytes);
    size_t n = read(fd, contenido+num_bytes, nbytes);
    num_bytes += n;
    return n;
}

size_t Archivo::escribe(void *buffer, size_t nbytes) {
    size_t bytes = write(fd, buffer, nbytes);
    return bytes;
}

size_t Archivo::obtiene_num_bytes() {
    return num_bytes;
}

const char* Archivo::get_contenido() {
    return contenido;
}

Archivo::~Archivo() {
    delete contenido;
    close(fd);
}


