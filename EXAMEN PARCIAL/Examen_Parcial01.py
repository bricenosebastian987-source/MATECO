def evaluar_paciente(nombre_archivo):
    try:
        with open(nombre_archivo, 'r') as f:
            # Leer las 60 lecturas del archivo
            lecturas = [float(x) for x in f.read().split()]
        
        if len(lecturas) < 60:
            print(f"Error: El archivo solo contiene {len(lecturas)} lecturas. Se requieren 60.")
            return
    except FileNotFoundError:
        print(f"Error: No se encontró el archivo '{nombre_archivo}'.")
        return

    # --- 1. DETECCIÓN DE TAQUICARDIA SOSTENIDA ---
    taquicardia_detectada = False
    consecutivos = 0
    inicio_taquicardia = 0
    
    for i in range(len(lecturas)):
        if lecturas[i] > 100:
            if consecutivos == 0:
                inicio_taquicardia = i + 1  # Guardar el minuto de inicio (1-based index)
            consecutivos += 1
            if consecutivos > 5:
                taquicardia_detectada = True
        else:
            # Si se rompe la racha antes de llegar a más de 5, se reinicia
            if consecutivos <= 5:
                consecutivos = 0
            # Si ya se detectó (consecutivos > 5), mantenemos la racha para saber el rango total

    fin_taquicardia = inicio_taquicardia + consecutivos - 1

    # --- 2. DETECCIÓN DE FATIGA POR ESFUERZO ---
    # Primeros 10 minutos (índices 0 a 9)
    suma_primeros = 0
    for i in range(10):
        suma_primeros += lecturas[i]
    promedio_primeros = suma_primeros / 10

    # Últimos 10 minutos (índices 50 a 59)
    suma_ultimos = 0
    for i in range(50, 60):
        suma_ultimos += lecturas[i]
    promedio_ultimos = suma_ultimos / 10

    # Verificar si aumentó en más del 20%
    limite_fatiga = promedio_primeros * 1.20
    fatiga_detectada = promedio_ultimos > limite_fatiga

    # --- IMPRESIÓN DE RESULTADOS ---
    print("\n" + "="*40)
    print("      RESULTADOS DEL ANÁLISIS CLÍNICO")
    print("="*40)
    
    hubo_problema = False

    if taquicardia_detectada:
        print(f"-> [ALERTA] Taquicardia Sostenida detectada.")
        print(f"   Producida entre los minutos {inicio_taquicardia} y {fin_taquicardia}.")
        hubo_problema = True

    if fatiga_detectada:
        print(f"-> [ALERTA] Fatiga por Esfuerzo detectada.")
        print(f"   Promedio primeros 10 min: {promedio_primeros:.2f} bpm")
        print(f"   Promedio últimos 10 min: {promedio_ultimos:.2f} bpm (Aumento > 20%)")
        hubo_problema = True
    else:
        # Si no hay fatiga, igual mostramos los promedios informativamente si el enunciado lo requiere
        if not hubo_problema:
            print(f"   Promedio primeros 10 min: {promedio_primeros:.2f} bpm")
            print(f"   Promedio últimos 10 min: {promedio_ultimos:.2f} bpm")

    if not hubo_problema:
        print("-> Paciente sin complicaciones cardiacas.")
    print("="*40 + "\n")


def main():
    while True:
        archivo = input("Ingrese el nombre del archivo de texto (ej. frecuencias.txt): ")
        evaluar_paciente(archivo)
        
        opcion = input("¿Desea evaluar a otro paciente? (S/N): ").strip().upper()
        if opcion != 'S':
            print("Cerrando el programa. Hasta luego.")
            break

if __name__ == "__main__":
    main()