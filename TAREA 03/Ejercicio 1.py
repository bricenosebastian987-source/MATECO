# Solicitamos el valor de N al usuario
N = int(input("Ingrese el valor de N: "))

# Inicialización de variables de control
contador = 1    # Controla el ciclo e indica el número natural actual
acumulador = 0  # Guarda la suma total de los números

# Bucle iterativo con la sentencia while
while contador <= N:
    acumulador += contador  # Se suma el valor actual del contador al acumulador
    contador += 1           # Se incrementa el contador para pasar al siguiente número

print(f"La sumatoria de los primeros {N} números naturales es: {acumulador}")