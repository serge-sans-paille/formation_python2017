import numpy as np
from math import sqrt

gamma_si = 6.67408e-11

eps = 0.1*0.1 # approx. 3 light year

def force(p1, p2, m2):
    dx = p2[0] - p1[0]
    dy = p2[1] - p1[1]
    dist = sqrt(dx**2 + dy**2 + eps)

    F = 0.
    if dist > 0:
        F = (gamma_si * m2) / (dist*dist*dist)

    return [F * dx, F * dy]
#pythran export compute_energy(float[], float[][], float[][])
def compute_energy(mass, particles, energy):
    print("pythran")
    energy[:] = 0.
    N = energy.shape[0]
    for i in range(N):
        for j in range(N):
            if i != j:
                F = force(particles[i, :2], particles[j,:2], mass[j])
                energy[i, 2:] += F
    energy[:, :2] = particles[:, 2:]
