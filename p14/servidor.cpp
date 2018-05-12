#include "gfx.h"
#include "SocketDatagrama.h"

double x_anterior = 0;
double y_anterior = 0;
bool bandera = false;

double transformar_x(double x){
    double nueva_x;
    double pi = (double) 3.1416;
    if(x > 0){
        nueva_x = 400 + (400 * x)/pi;
    } else {
        nueva_x = 400 + (400 * x)/pi;
    }

    return nueva_x;
    
}

/*
* pi - 400
* a - x
*/

double transformar_y(double y){
    double nueva_y;
    double incremento = (double) 6/600;
    if(y < 0){
        nueva_y = 300 + (( y * (-1)) / incremento);
    }
    nueva_y = (3-y)/incremento;
    return nueva_y;
}
/*
*
*/
void pintar(double x, double y) {
    unsigned int nuevo_x = transformar_x(x);
    unsigned int nuevo_y = transformar_y(y);
    gfx_point(nuevo_x, nuevo_y);
    printf("x=%d, %f y=%d %f\n", nuevo_x, x, nuevo_y, y);
}


int main(int argc, char const *argv[]) {
    gfx_open(800, 600, "Serie de Fourier");
    gfx_line(400, 0, 400, 600);
    gfx_line(0, 300, 800, 300);
    double a = 0;
    double b = 0;
    char otro[sizeof(double)];
    char otro2[sizeof(double)];
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(7200);
    PaqueteDatagrama paquete(2*sizeof(double));
    while (1) {
        if (gfx_event_waiting()) break;
        printf("%s\n", "ESPERANDO...");
        printf("Recibidos = %d\n", cliente.recibe(paquete));
        printf("Mensaje de: %s:%d\n", paquete.obtieneDireccion(), paquete.obtienePuerto());

        for (int i = 0; i < 8; i++){
            otro[i] = paquete.obtieneDatos()[7-i];
            otro2[i] = paquete.obtieneDatos()[15-i];
        }
        memcpy(&a, otro, sizeof(double));
        memcpy(&b, otro2, sizeof(double));
        pintar(a, b);
    }
    return 0;
}