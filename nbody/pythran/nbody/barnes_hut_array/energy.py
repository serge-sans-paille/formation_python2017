import numpy as np
from .quadTree import quadArray
import time

def compute_energy(mass, particles, energy):
    bmin = np.min(particles[: ,:2], axis=0)
    bmax = np.max(particles[: ,:2], axis=0)
    root = quadArray(bmin, bmax, particles.shape[0])

    root.buildTree(particles)

    t1 = time.time()
    root.computeMassDistribution(particles, mass)
    t2 = time.time()
    print(t2-t1)

    for i in range(particles.shape[0]):
        acc = root.computeForce(particles[i])
        energy[i, 2:] = acc
    energy[:, :2] = particles[:, 2:]
