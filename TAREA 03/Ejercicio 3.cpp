#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;

    // Inicialización de las variables de control
    int contador = 1;   // Controla cuántas veces hemos sumado A
    int resultado = 0;  // Acumulador para almacenar las sumas sucesivas

    // El ciclo se repite mientras no hayamos alcanzado el límite B
    while (contador <= B) {
        resultado += A; // Sumamos el valor de A al acumulador
        contador++;     // Incrementamos el contador
    }

    cout << "El resultado de " << A << " x " << B << " por sumas sucesivas es: " << resultado << endl;
    cout << "(Verificacion: la variable B sigue valiendo: " << B << ")" << endl;

    return 0;
}