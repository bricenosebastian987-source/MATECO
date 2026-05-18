#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "--- Iniciando Juego TrikiTraka (1 al 50) ---" << endl;

    // Control de secuencia del 1 al 50
    for (int i = 1; i <= 50; i++) {
        
        // REGLA 1: Múltiplo de ambos (3 y 5)
        // Se puede usar (i % 3 == 0 && i % 5 == 0) o simplemente (i % 15 == 0)
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "TrikiTraka" << endl;
        } 
        // REGLA 2: Múltiplo solo de 3
        else if (i % 3 == 0) {
            cout << "Triki" << endl;
        } 
        // REGLA 3: Múltiplo solo de 5
        else if (i % 5 == 0) {
            cout << "Traka" << endl;
        } 
        // REGLA 4: Ninguno de los anteriores
        else {
            cout << i << endl;
        }
    }

    return 0;
}