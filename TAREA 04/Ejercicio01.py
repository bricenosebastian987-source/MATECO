import numpy as np
import matplotlib.pyplot as plt
import sympy as sp

# Definición de la variable simbólica y la amplitud
t = sp.symbols('t')
A = 1

# Función de posición
x = A * sp.exp(-t/3) * sp.cos(2 * sp.pi * t + sp.pi/4)

# Primera derivada: velocidad
v = sp.diff(x, t)

# Segunda derivada: aceleración
a = sp.diff(v, t)

# Mostrar las expresiones obtenidas
print("Posición x(t):")
print(sp.simplify(x))

print("\nVelocidad v(t):")
print(sp.simplify(v))

print("\nAceleración a(t):")
print(sp.simplify(a))

# Conversión de las funciones simbólicas a funciones numéricas
x_num = sp.lambdify(t, x, 'numpy')
v_num = sp.lambdify(t, v, 'numpy')
a_num = sp.lambdify(t, a, 'numpy')

# Intervalo de tiempo de 0 a 6 segundos
t_vals = np.linspace(0, 6, 1000)

# Evaluación de las funciones en el intervalo
x_vals = x_num(t_vals)
v_vals = v_num(t_vals)
a_vals = a_num(t_vals)

# Creación de tres subgráficas en una sola ventana
fig, axs = plt.subplots(3, 1, figsize=(10, 8))

# Gráfica de la posición
axs[0].plot(t_vals, x_vals, color='red')
axs[0].set_title('Posición x(t)')
axs[0].set_xlabel('Tiempo (s)')
axs[0].set_ylabel('Posición (m)')
axs[0].grid(True)

# Gráfica de la velocidad
axs[1].plot(t_vals, v_vals, color='blue')
axs[1].set_title('Velocidad v(t)')
axs[1].set_xlabel('Tiempo (s)')
axs[1].set_ylabel('Velocidad (m/s)')
axs[1].grid(True)

# Gráfica de la aceleración
axs[2].plot(t_vals, a_vals, color='green')
axs[2].set_title('Aceleración a(t)')
axs[2].set_xlabel('Tiempo (s)')
axs[2].set_ylabel('Aceleración (m/s²)')
axs[2].grid(True)

# Ajuste automático de espacios entre gráficas
plt.tight_layout()

# Mostrar las gráficas
plt.show()