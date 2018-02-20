#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int numero1;
    int numero2;
    float numero3;
    cout << "Ingresa un entero: ";
    cin >> numero1;
    cout << "Ingresa otro entero: ";
    cin >> numero2;
    cout << "Ingresa un flotante: ";
    cin >> numero3;
    cout << "Entero entre entero: ";
    cout << (numero1/numero2);
    cout << "\nEntero entre flotante: ";
    cout << (numero1/numero3);
    cout << "\nFlotante entre entero: ";
    cout << (numero3/numero1);
    return 0;
}