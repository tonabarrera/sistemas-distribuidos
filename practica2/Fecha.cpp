#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa){
    mes = mm;
    dia = dd;
    anio = aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)  {
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}
void Fecha::muestraFecha() {
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

bool Fecha::leapyr() {
    if ((anio % 400 == 0) || (anio% 4== 0 && anio%100))
        return true;
    return false;
}
