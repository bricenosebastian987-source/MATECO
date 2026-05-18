#include <iostream>

using namespace std;

int main() {
    double base;
    int exponente;
    long double resultado = 1.0; // Acumulador de producto inicializado en 1

    // 1. Entrada de datos
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente (entero positivo): ";
    cin >> exponente;

    // 2. Lógica de potencias
    if (exponente < 0) {
        cout << "Este programa solo calcula exponentes enteros no negativos." << endl;
    } else if (exponente == 0) {
        // Cualquier número elevado a 0 es 1 (ya inicializado en 1)
        resultado = 1.0;
    } else {
        // Control de secuencia: multiplicamos la base 'exponente' veces
        for (int i = 1; i <= exponente; i++) {
            resultado *= base; // resultado = resultado * base
        }
    }

    // 3. Resultado
    cout << base << " elevado a la " << exponente << " es: " << resultado << endl;

    return 0;
}