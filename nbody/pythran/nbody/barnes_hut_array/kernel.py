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
#pythran export compute_force(int, int32[], float64[][], float64[], float64[][], float64[])
def compute_force(nbodies, children, center_of_mass, mass, cell_radius, p):

    depth = 0
    localPos = np.zeros(2*nbodies, dtype=np.int32)
    localNode = np.zeros(2*nbodies, dtype=np.int32)
    localNode[0] = nbodies

    pos = p[:2]
    acc = np.zeros(2)

    while depth >= 0:
        while localPos[depth] < 4:
            child = children[localNode[depth] + localPos[depth]]
            # print('child 1', child, localNode[depth] + localPos[depth])
            localPos[depth] += 1
            if child >= 0:
                if child < nbodies:
                    F = force(pos, center_of_mass[child], mass[child])
                    acc += F
                else:
                    dx = center_of_mass[child, 0] - pos[0]
                    dy = center_of_mass[child, 1] - pos[1]
                    dist = np.sqrt(dx**2 + dy**2)
                    if dist != 0 and cell_radius[child - nbodies][0]/dist <.5:
                        F = force(pos, center_of_mass[child], mass[child])
                        acc += F
                    else:
                        depth += 1
                        localNode[depth] = nbodies + 4*(child-nbodies)
                        localPos[depth] = 0
        depth -= 1
    return acc
