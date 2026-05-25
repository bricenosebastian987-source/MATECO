#include <iostream>
#include <iomanip> // Para manejar precisión si el número es muy grande

using namespace std;

int main() {
    int N;
    // Usamos double para permitir factoriales más grandes que 20
    long double factorial = 1.0; 

    cout << "Ingrese un número para calcular su factorial: ";
    cin >> N;

    if (N < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        // Control de secuencia: de 1 hasta N
        for (int i = 1; i <= N; i++) {
            factorial *= i; // Acumulador de producto: factorial = factorial * i
        }

        // fixed y setprecision(0) evitan la notación científica en números grandes
        cout << "El factorial de " << N << " es: " << fixed << setprecision(0) << factorial << endl;
    }

    return 0;
}