#include "Respuesta.hpp"
#include "Mensaje.h"
#include "gfxModified.h"

#define MICRO_SEC_PER_DAY 86400000000
#define ANCHURA 800
#define ALTURA 180

int main(int argc, char const *argv[]) {
    Respuesta respuesta(7200);
    unsigned long microsegundos;
    long hms;
    int dec_sec;
    char valor[15] = {42};
    struct timeval tiempo;
    time_t auxiliar;
    struct tm *timeinfo;
    struct mensaje *msg;
    gfx_open(ANCHURA, ALTURA, "Ejemplo gfx_display_ascii");
    gfx_color(87,1,2);
    long resultado[1];
    while(true) {
        printf("%s\n", "ESPERANDO...");
        msg = respuesta.getRequest();
        memcpy((char *)resultado, msg->arguments, sizeof(long));
        printf("%ld\n", resultado[0]);
        break;
    }
    
    while(true){
        gettimeofday(&tiempo, NULL);
        microsegundos = tiempo.tv_sec * 1000000L + tiempo.tv_usec;
        hms = microsegundos % MICRO_SEC_PER_DAY;
        hms = (hms + MICRO_SEC_PER_DAY) % MICRO_SEC_PER_DAY;
        dec_sec = (hms % 1000000) / 10000;

        auxiliar = tiempo.tv_sec;
        printf("SEC: %ld\n", tiempo.tv_sec);
        timeinfo = localtime(&auxiliar);
        strftime(valor, 15, "%H:%M:%S:", timeinfo);

        string valor2 = to_string(dec_sec);
        valor[14] = valor2.c_str()[0];
        valor[15] = valor2.c_str()[1];
        respuesta.sendReply((char *) &tiempo.tv_sec, msg->IP, msg->puerto);
        gfx_clear();

        // decima de segundos
        gfx_display_ascii(610, 20, 10 , valor[14]);
        gfx_display_ascii(690, 20, 10 , valor[15]);

        // segundos
        gfx_display_ascii(410, 20, 10 , valor[6]);
        gfx_display_ascii(490, 20, 10 , valor[7]);

        // minutos
        gfx_display_ascii(210, 20, 10 , valor[3]);
        gfx_display_ascii(290, 20, 10 , valor[4]);

        // horas
        gfx_display_ascii(10, 20, 10 , valor[0]);
        gfx_display_ascii(90, 20, 10 , valor[1]);
        gfx_flush();
        break;
    }
    return 0;
}