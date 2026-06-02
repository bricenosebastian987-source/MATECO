# Solicitamos el número entero al usuario
numero = int(input("Ingrese un número entero: "))

# Convertimos a valor absoluto para que funcione con números negativos
temp = abs(numero)

contador_digitos = 0

# Caso especial: si el número es exactamente 0
if temp == 0:
    contador_digitos = 1
else:
    # Bucle iterativo divisivo
    while temp > 0:
        contador_digitos += 1  # Contamos un dígito
        temp = temp // 10      # División entera para eliminar el último dígito

print(f"El número {numero} tiene {contador_digitos} dígitos.")