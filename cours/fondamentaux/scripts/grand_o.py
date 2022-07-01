import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import spline

plt.rc('font', size=18)
plt.rc('legend', fontsize=28)
plt.rc('axes', labelsize=28)

x = np.arange(0, 101, 10)
f = [0, 20, 35, 45, 50, 55, 60, 65, 70, 75, 80]

fig, ax = plt.subplots()
xnew = np.linspace(0, 100)
f_interpolated = spline(x, f, xnew)

ax.plot(xnew, f_interpolated, linewidth=2)

ax.set_xlabel('$n$')
ax.set_ylabel('$f(n)$')

ax.set_xlim([0, 80])
ax.set_ylim([0, 80])

ax.plot(x, x, label='$g(n)$', color='red', linewidth=2)

ax.axvline(x=60, color='black', linestyle='--', label='$n_0$', linewidth=2)

ax.set_aspect('equal')

plt.legend(loc='upper left')
plt.tight_layout()
plt.show()