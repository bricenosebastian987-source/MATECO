#include <iostream>

using namespace std;

int main() {
    // Declaración de variables
    int N;
    long long suma = 0; // Acumulador inicializado en 0

    // 1. Entrada de datos
    cout << "Ingrese un número entero positivo N: ";
    cin >> N;

    // Validación básica para asegurar que N sea positivo
    if (N < 1) {
        cout << "Por favor, ingrese un número mayor a 0." << endl;
        return 1; 
    }

    // 2. Control de secuencia y Acumulador
    // El bucle inicia en 1 y termina cuando i es igual a N
    for (int i = 1; i <= N; i++) {
        suma += (i * i); // Sumamos el cuadrado de 'i' al acumulador
    }

    // 3. Salida de resultados
    cout << "La suma de los cuadrados desde 1 hasta " << N << " es: " << suma << endl;

    return 0;
}