#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Ingrese el valor de N: ";
    cin >> N;

    // Inicialización de variables de control
    int contador = 1;   // Controla el ciclo e indica el número natural actual
    int acumulador = 0; // Guarda la suma total de los números

    // Bucle iterativo con la sentencia while
    while (contador <= N) {
        acumulador += contador; // Se suma el valor actual del contador al acumulador
        contador++;             // Se incrementa el contador para pasar al siguiente número
    }

    cout << "La sumatoria de los primeros " << N << " numeros naturales es: " << acumulador << endl;

    return 0;
}