import numpy as np
import matplotlib.pyplot as plt
import sympy as sp

# Definición de la variable simbólica y la amplitud
t = sp.symbols('t')
A = 1

# Función de posición
x = A * sp.exp(-t/3) * sp.cos(2 * sp.pi * t + sp.pi/4)

# Obtención de la velocidad y aceleración mediante SymPy
v = sp.diff(x, t)
a = sp.diff(v, t)

# Mostrar las expresiones derivadas
print("Posición x(t):")
sp.pprint(sp.simplify(x))

print("\nVelocidad v(t):")
sp.pprint(sp.simplify(v))

print("\nAceleración a(t):")
sp.pprint(sp.simplify(a))

# Conversión a funciones numéricas
x_num = sp.lambdify(t, x, 'numpy')
v_num = sp.lambdify(t, v, 'numpy')
a_num = sp.lambdify(t, a, 'numpy')

# Intervalo de tiempo
t_vals = np.linspace(0, 6, 1000)

# Evaluación de las funciones
x_vals = x_num(t_vals)
v_vals = v_num(t_vals)
a_vals = a_num(t_vals)

# Creación de las subgráficas
fig, axs = plt.subplots(3, 1, figsize=(10, 10))

# Posición
axs[0].plot(t_vals, x_vals, color='red')
axs[0].set_title('Posición x(t)')
axs[0].set_xlabel('Tiempo (s)')
axs[0].set_ylabel('Posición (m)')
axs[0].grid(True)

# Velocidad
axs[1].plot(t_vals, v_vals, color='blue')
axs[1].set_title('Velocidad v(t)')
axs[1].set_xlabel('Tiempo (s)')
axs[1].set_ylabel('Velocidad (m/s)')
axs[1].grid(True)

# Aceleración
axs[2].plot(t_vals, a_vals, color='green')
axs[2].set_title('Aceleración a(t)')
axs[2].set_xlabel('Tiempo (s)')
axs[2].set_ylabel('Aceleración (m/s²)')
axs[2].grid(True)

# Título general
fig.suptitle('Oscilación amortiguada: posición, velocidad y aceleración', fontsize=14)

# Ajuste de espacios
plt.tight_layout()

# Mostrar las gráficas
plt.show()