import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
from scipy.integrate import simpson
from matplotlib.widgets import Slider

# Definición de la variable simbólica
t = sp.symbols('t')
A = 1

# Función de posición
x = A * sp.exp(-t/3) * sp.cos(2 * sp.pi * t + sp.pi/4)

# Velocidad y aceleración
v = sp.diff(x, t)
a = sp.diff(v, t)

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

# Crear figura
fig, axs = plt.subplots(3, 1, figsize=(10, 9))
plt.subplots_adjust(bottom=0.25)

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

# Cuadro para mostrar resultados
texto = fig.text(
    0.15,
    0.02,
    '',
    fontsize=10,
    bbox=dict(facecolor='white')
)

# Slider
ax_slider = plt.axes([0.2, 0.1, 0.6, 0.03])
slider = Slider(
    ax=ax_slider,
    label='t (s)',
    valmin=0,
    valmax=6,
    valinit=6,
    valstep=0.1
)

# Función que actualiza las integrales
def actualizar(valor):

    t_max = slider.val

    indices = t_vals <= t_max

    t_int = t_vals[indices]
    v_int = v_vals[indices]
    a_int = a_vals[indices]

    # Método del trapecio
    int_v_trap = np.trapz(v_int, t_int)
    int_a_trap = np.trapz(a_int, t_int)

    # Método de Simpson
    int_v_simp = simpson(v_int, t_int)
    int_a_simp = simpson(a_int, t_int)

    texto.set_text(
        f't = {t_max:.1f} s\n\n'
        f'∫v(t)dt Trapecio = {int_v_trap:.6f}\n'
        f'∫v(t)dt Simpson  = {int_v_simp:.6f}\n\n'
        f'∫a(t)dt Trapecio = {int_a_trap:.6f}\n'
        f'∫a(t)dt Simpson  = {int_a_simp:.6f}'
    )

    fig.canvas.draw_idle()

slider.on_changed(actualizar)

# Mostrar resultados iniciales
actualizar(6)

plt.show()