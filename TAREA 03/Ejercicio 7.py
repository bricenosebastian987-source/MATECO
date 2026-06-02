def raiz_newton_raphson(s: float) -> float:
    if s < 0:
        raise ValueError("Raíz imaginaria")
    if s == 0:
        return 0.0
    
    aproximacion = s / 2.0  # Estimación inicial
    tolerancia = 1e-7       # Límite de error aceptable (epsilon)
    diferencia = s          # Variable para evaluar el criterio de parada
    
    # Bucle controlado por convergencia numérica
    while diferencia > tolerancia:
        anterior = aproximacion
        
        # Fórmula de optimización matemática: x_{n+1} = 0.5 * (x_n + S / x_n)
        aproximacion = 0.5 * (anterior + (s / anterior))
        
        # Calculamos el valor absoluto del cambio para verificar estabilidad
        diferencia = abs(aproximacion - anterior)
        
    return aproximacion

# Bloque principal de prueba (main)
if __name__ == "__main__":
    # Imprime 5.0 de la misma forma que el ejemplo de C++
    print(raiz_newton_raphson(25))