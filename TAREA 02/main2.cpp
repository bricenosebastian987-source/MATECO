#include <iostream>

using namespace std;

int main() {
    int numero;

    cout << "Ingrese el número para ver su tabla inversa: ";
    cin >> numero;

    cout << "--- Tabla del " << numero << " (Inversa) ---" << endl;

    // Control de secuencia: de 10 a 1
    // i-- decrementa el valor en cada vuelta
    for (int i = 10; i >= 1; i--) {
        int resultado = numero * i;
        cout << numero << " x " << i << " = " << resultado << endl;
    }

    return 0;
}