# Solicitamos los dos números enteros al usuario
a = int(input("Ingrese el primer número (a): "))
b = int(input("Ingrese el segundo número (b): "))

# Guardamos los valores originales para el mensaje final
original_a = a
original_b = b

# El bucle se ejecuta mientras b sea diferente de 0
while b != 0:
    # Asignación simultánea: a toma el valor de b, y b toma el residuo de a % b
    a, b = b, a % b

# Al terminar el ciclo, el MCD queda almacenado en la variable 'a'
print(f"El MCD de {original_a} y {original_b} es: {a}")