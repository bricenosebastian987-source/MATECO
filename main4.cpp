#include <iostream>

using namespace std;

int main() {
    int ancho, alto;

    // 1. Entrada de dimensiones
    cout << "Ingrese el ancho del rectangulo: ";
    cin >> ancho;
    cout << "Ingrese el alto del rectangulo: ";
    cin >> alto;

    cout << "\nDibujando rectangulo...\n" << endl;

    // 2. Bucle externo para las FILAS (Alto)
    for (int i = 0; i < alto; i++) {
        
        // 3. Bucle interno para las COLUMNAS (Ancho)
        for (int j = 0; j < ancho; j++) {
            cout << "* "; // Imprime el caracter en la misma fila
        }
        
        // 4. Salto de linea al terminar cada fila
        cout << endl;
    }

    return 0;
}