#include <iostream>

using namespace std;

int main() {
    int N;
    int contadorDivisores = 0; // Contador para determinar primalidad

    cout << "Ingrese un numero entero positivo: ";
    cin >> N;

    if (N <= 0) {
        cout << "Por favor, ingrese un numero mayor a cero." << endl;
        return 1;
    }

    cout << "Los divisores de " << N << " son: ";

    // Control de secuencia: Probamos todos los numeros desde 1 hasta N
    for (int i = 1; i <= N; i++) {
        // Un numero es divisor si el residuo de la division es 0
        if (N % i == 0) {
            cout << i << " ";
            contadorDivisores++; // Incrementamos el contador cada vez que hallamos uno
        }
    }

    // Lógica de primalidad
    cout << "\n\nTotal de divisores encontrados: " << contadorDivisores << endl;

    if (contadorDivisores == 2) {
        cout << "Resultado: " << N << " es un NUMERO PRIMO." << endl;
    } else {
        if (N == 1) {
            cout << "Resultado: El numero 1 no se considera primo ni compuesto." << endl;
        } else {
            cout << "Resultado: " << N << " es un NUMERO COMPUESTO." << endl;
        }
    }

    return 0;
}