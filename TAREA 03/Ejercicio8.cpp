#include <iostream>
#include <vector>

// Función que realiza la descomposición en factores primos
std::vector<int> factorizar_primos(int n) {
    std::vector<int> factores;
    int divisor = 2; // Primer número primo matemáticamente posible

    // Bucle externo: reduce el número n hasta que se vuelva 1
    while (n > 1) {
        // Bucle interno: extrae el divisor actual tantas veces como sea divisible
        while (n % divisor == 0) {
            factores.push_back(divisor); // Almacenamos el factor primo hallado (push_back equivale a .append)
            n = n / divisor;             // Reducción matemática estricta de n
        }
        divisor += 1; // Pasamos al siguiente candidato (los compuestos se saltarán automáticamente)
    }

    return factores;
}

int main() {
    int numero = 56;
    std::vector<int> resultado = factorizar_primos(numero);

    // Formateamos la salida para que se vea igual que el resultado esperado en Python: [2, 2, 2, 7]
    std::cout << "[";
    for (size_t i = 0; i < resultado.size(); ++i) {
        std::cout << resultado[i];
        if (i < resultado.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << "Resultado esperado: [2, 2, 2, 7] porque 2^3 * 7 = 56" << std::endl;

    return 0;
}