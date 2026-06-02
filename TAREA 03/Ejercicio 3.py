# Solicitamos los dos números enteros al usuario
A = int(input("Ingrese el valor de A: "))
B = int(input("Ingrese el valor de B: "))

# Inicialización de las variables de control
contador = 1     # Controla cuántas veces hemos sumado A
resultado = 0    # Acumulador para almacenar las sumas sucesivas

# El ciclo se repite utilizando B como límite estricto sin modificarlo
while contador <= B:
    resultado += A   # Sumamos el valor de A al acumulador
    contador += 1    # Incrementamos el contador

print(f"El resultado de {A} x {B} por sumas sucesivas es: {resultado}")
print(f"(Verificación: la variable B sigue valiendo: {B})")