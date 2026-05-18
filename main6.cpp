#include <iostream>

using namespace std;

int main() {
    int numero;
    int sumaPares = 0;      // Acumulador de suma
    int contadorImpares = 0; // Acumulador de conteo (contador)

    cout << "Por favor, ingrese 10 numeros enteros:" << endl;

    // Control de secuencia: exactamente 10 repeticiones
    for (int i = 1; i <= 10; i++) {
        cout << "Numero " << i << ": ";
        cin >> numero;

        // Filtro de pares e impares usando el operador residuo (%)
        if (numero % 2 == 0) {
            // Si el residuo de dividir entre 2 es 0, es PAR
            sumaPares += numero; 
        } else {
            // De lo contrario, es IMPAR
            contadorImpares++; 
        }
    }

    // Salida de resultados
    cout << "\n--- Resultados ---" << endl;
    cout << "La suma de los numeros pares es: " << sumaPares << endl;
    cout << "La cantidad de numeros impares ingresados es: " << contadorImpares << endl;

    return 0;
}