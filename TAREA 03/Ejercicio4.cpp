#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Ingrese el primer numero (a): ";
    cin >> a;
    cout << "Ingrese el segundo numero (b): ";
    cin >> b;

    // Guardamos los valores originales para mostrarlos al final
    int original_a = a;
    int original_b = b;

    // El algoritmo de Euclides dice que repetimos mientras b no sea 0
    while (b != 0) {
        int temporal = b; // Guardamos el valor actual de b
        b = a % b;        // b pasa a ser el residuo de a dividido entre b
        a = temporal;     // a toma el antiguo valor de b
    }

    // Al romperse el ciclo, el MCD queda almacenado en la variable 'a'
    cout << "El MCD de " << original_a << " y " << original_b << " es: " << a << endl;

    return 0;
}

