#include <cstring>
#include "paquetedatagrama.hpp"
/**
 * Datos, Size, IP, Puerto
 */
PaqueteDatagrama::PaqueteDatagrama(char* data, unsigned int length, char* Ip, int port) : longitud(length),puerto(port)
{
    datos = new char[longitud];
    std::memcpy(datos,data,length);
    std::strcpy(ip,Ip);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int length) : longitud(length)
{
    datos = new char[longitud];
}

PaqueteDatagrama::~PaqueteDatagrama()
{
    delete datos;
}

char* PaqueteDatagrama::obtieneDatos()
{
    return datos;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
    return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
    return puerto;
}

char * PaqueteDatagrama::obtieneDireccion()
{
    return ip;
}

void PaqueteDatagrama::inicializaDatos(char * data)
{
    std::memcpy(datos,data,longitud);
}

void PaqueteDatagrama::inicializaPuerto(int port)
{
    puerto = port;
}

void PaqueteDatagrama::inicializaIp(char * Ip)
{
    std::strcpy(ip,Ip);
}