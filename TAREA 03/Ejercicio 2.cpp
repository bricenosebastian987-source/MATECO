#include <iostream>
#include <cmath> // Para usar abs() por si el usuario ingresa un número negativo
using namespace std;

int main() {
    long long numero; // Usamos long long por si el usuario ingresa un número muy grande
    cout << "Ingrese un numero entero: ";
    cin >> numero;

    // Convertimos a positivo para manejar números negativos correctamente
    long long temp = abs(numero); 
    
    int contador_digitos = 0;

    // Caso especial: si el número es exactamente 0, tiene 1 dígito
    if (temp == 0) {
        contador_digitos = 1;
    } else {
        // Bucle iterativo divisivo
        while (temp > 0) {
            contador_digitos++; // Contamos un dígito
            temp = temp / 10;   // Eliminamos el último dígito mediante división entera
        }
    }

    cout << "El numero " << numero << " tiene " << contador_digitos << " digitos." << endl;

    return 0;
}