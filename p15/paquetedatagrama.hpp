#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama{
public:
    /**
     * Datos, Tamaño, IP, Puerto
     */ 
    PaqueteDatagrama(char*, unsigned int, char*, int);
    PaqueteDatagrama(unsigned int);
    ~PaqueteDatagrama();
    char* obtieneDireccion();
    unsigned int obtieneLongitud();
    int obtienePuerto();
    char* obtieneDatos();
    void inicializaPuerto(int);
    void inicializaIp(char*);
    void inicializaDatos(char*);
private:
    char* datos;
    char ip[16];
    unsigned int longitud;
    int puerto;
};

#endif