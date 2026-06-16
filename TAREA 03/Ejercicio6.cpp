#include <iostream>
using namespace std;

int conjetura_collatz(long long n) {
    int pasos = 0;

    // La condición de parada matemática es alcanzar el valor estable de 1
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;     // Si es par, se reduce a la mitad
        } else {
            n = 3 * n + 1; // Si es impar, se escala y se vuelve par
        }
        pasos += 1;        // Contamos la mutación de la variable
    }

    return pasos;
}

int main() {
    long long numero = 6;
    
    // Imprime la cantidad de pasos (8) de la misma forma que el ejemplo de Python
    cout << conjetura_collatz(numero) << endl; 
    
    // Mensaje de texto equivalente al comentario en Python para verificar la secuencia
    cout << "Secuencia: 6->3->10->5->16->8->4->2->1. Pasos: 8" << endl;

    return 0;
}