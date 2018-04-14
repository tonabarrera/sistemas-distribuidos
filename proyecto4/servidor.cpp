#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
#include "SocketDatagrama.h"

int main(int argc, char const *argv[]) {
    printf("%s\n", "Servidor");
    if (argc < 2) {
        printf("%s\n", "Faltan parametros");
        return -1;
    }
    SocketDatagrama servidor(7200);
    int L = atoi(argv[1]);

    gfx_open(L+10, L+10, "Aranias");
    gfx_color(0, 200, 100);
    gfx_clear();    
    gfx_line(10, 10, L, 10);
    gfx_line(10, 10, 10, L);
    gfx_line(L, 10, L, L);
    gfx_line(L, L, 10, L);
    gfx_flush();
    gfx_color(200, 0, 50);
    gfx_line(50, 50, 100, 100);
    gfx_flush();
    while (1) {
        if (gfx_event_waiting()) break;
        // Esperar
        // Actualizar coordenadas
        // Pintar
        // Mandar coordenadas de todas las arañas en una estructura
    }
    return 0;
}