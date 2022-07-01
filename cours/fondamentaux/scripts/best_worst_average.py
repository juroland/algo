import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import spline

plt.rc('font', size=16)
plt.rc('legend', fontsize=18)
plt.rc('axes', labelsize=18)

n = [1, 2, 3, 4]
nsteps = [[10], [12, 14, 16], [14, 16, 18, 19, 21, 25],
          [19, 21, 22, 24, 27, 29, 30, 32, 34, 35, 38]]

fig, ax = plt.subplots()

for i in range(len(n)):
    ax.plot([n[i]] * len(nsteps[i]), nsteps[i], 'o', color='black')

worst = [max(s) for s in nsteps]
average = [np.mean(s) for s in nsteps]
best = [min(s) for s in nsteps]

ax.plot(n, worst, label='Pire cas', linewidth=2)
ax.plot(n, average, label='Cas moyen', linewidth=2)
ax.plot(n, best, label='Meilleur cas', linewidth=2)

ax.set_xlabel('Taille du problème')
ax.set_ylabel("Nombre d'étapes")

ax.set_xlim([0, 5])
ax.set_ylim([0, 40])

plt.legend(loc='upper left')

plt.show()