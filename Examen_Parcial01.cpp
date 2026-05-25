#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void evaluarPaciente(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'.\n";
        return;
    }

    double lecturas[60];
    int totalLecturas = 0;

    // Leer las 60 frecuencias del archivo
    while (totalLecturas < 60 && archivo >> lecturas[totalLecturas]) {
        totalLecturas++;
    }
    archivo.close();

    if (totalLecturas < 60) {
        cout << "Error: El archivo solo contiene " << totalLecturas << " lecturas. Se requieren 60.\n";
        return;
    }

    // --- 1. DETECCIÓN DE TAQUICARDIA SOSTENIDA ---
    bool taquicardiaDetectada = false;
    int consecutivos = 0;
    int inicioTaquicardia = 0;

    for (int i = 0; i < 60; i++) {
        if (lecturas[i] > 100) {
            if (consecutivos == 0) {
                inicioTaquicardia = i + 1; // Minuto en formato humano (1 a 60)
            }
            consecutivos++;
            if (consecutivos > 5) {
                taquicardiaDetectada = true;
            }
        } else {
            if (consecutivos <= 5) {
                consecutivos = 0;
            }
        }
    }
    int finTaquicardia = inicioTaquicardia + consecutivos - 1;

    // --- 2. DETECCIÓN DE FATIGA POR ESFUERZO ---
    double sumaPrimeros = 0;
    for (int i = 0; i < 10; i++) {
        sumaPrimeros += lecturas[i];
    }
    double promedioPrimeros = sumaPrimeros / 10.0;

    double sumaUltimos = 0;
    for (int i = 50; i < 60; i++) {
        sumaUltimos += lecturas[i];
    }
    double promedioUltimos = sumaUltimos / 10.0;

    bool fatigaDetectada = promedioUltimos > (promedioPrimeros * 1.20);

    // --- IMPRESIÓN DE RESULTADOS ---
    cout << "\n========================================" << endl;
    cout << "      RESULTADOS DEL ANÁLISIS CLÍNICO" << endl;
    cout << "========================================" << endl;

    bool huboProblema = false;
    cout << fixed << setprecision(2);

    if (taquicardiaDetectada) {
        cout << "-> [ALERTA] Taquicardia Sostenida detectada." << endl;
        cout << "   Producida entre los minutos " << inicioTaquicardia << " y " << finTaquicardia << "." << endl;
        huboProblema = true;
    }

    if (fatigaDetectada) {
        cout << "-> [ALERTA] Fatiga por Esfuerzo detectada." << endl;
        cout << "   Promedio primeros 10 min: " << promedioPrimeros << " bpm" << endl;
        cout << "   Promedio últimos 10 min: " << promedioUltimos << " bpm (Aumento > 20%)" << endl;
        huboProblema = true;
    } else if (!huboProblema) {
        cout << "   Promedio primeros 10 min: " << promedioPrimeros << " bpm" << endl;
        cout << "   Promedio últimos 10 min: " << promedioUltimos << " bpm" << endl;
    }

    if (!huboProblema) {
        cout << "-> Paciente sin complicaciones cardiacas." << endl;
    }
    cout << "========================================\n" << endl;
}

int main() {
    string nombreArchivo;
    char opcion;

    do {
        cout << "Ingrese el nombre del archivo de texto (ej. frecuencias.txt): ";
        cin >> nombreArchivo;

        evaluarPaciente(nombreArchivo);

        cout << "¿Desea evaluar a otro paciente? (S/N): ";
        cin >> opcion;
        opcion = toupper(opcion);

    } while (opcion == 'S');

    cout << "Cerrando el programa. Hasta luego." << endl;
    return 0;
}