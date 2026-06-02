def decimal_a_binario(n: int) -> str:
    # Caso especial: si el número es exactamente 0
    if n == 0:
        return "0"
    
    binario = ""
    
    # Mientras el número sea mayor a cero, extraemos su paridad
    while n > 0:
        residuo = n % 2
        # Insertamos el residuo al principio del string para respetar el peso matemático
        binario = str(residuo) + binario
        n = n // 2  # División entera para la siguiente iteración
        
    return binario

# Bloque principal de prueba (main)
if __name__ == "__main__":
    # Imprime 1101 de la misma forma que el ejemplo de C++
    print(decimal_a_binario(13))