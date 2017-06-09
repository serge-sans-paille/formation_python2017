import numpy as np
from ..forces import force
from . import pythran_functions

class quadArray:
    def __init__(self, bmin, bmax, size):
        self.nbodies = size
        self.child = -np.ones(4*(2*size+1), dtype=np.int32)
        self.bmin = np.asarray(bmin)
        self.bmax = np.asarray(bmax)
        self.center = .5*(self.bmin + self.bmax)
        self.box_size = (self.bmax - self.bmin)
        self.ncell = 0
        self.cell_center = np.zeros((2*size+1, 2))
        self.cell_radius = np.zeros((2*size+1, 2))
        self.cell_center[0] = self.center
        self.cell_radius[0] = self.box_size

    def buildTree(self, particles):
        self.ncell = pythran_functions.buildTree(self.center, self.box_size, self.child, self.cell_center, self.cell_radius, particles)

    def computeMassDistribution(self, particles, mass):
        self.mass = np.zeros(self.nbodies + self.ncell + 1)
        self.mass[:self.nbodies] = mass
        self.center_of_mass = np.zeros((self.nbodies + self.ncell + 1, 2))
        self.center_of_mass[:self.nbodies] = particles[:, :2]
        for i in range(self.ncell, -1, -1):
            elements = self.child[self.nbodies + 4*i:self.nbodies + 4*i + 4]
            #print('elements', i, elements, self.center_of_mass[elements[elements>=0]]*self.mass[elements[elements>=0]])
            self.mass[self.nbodies + i] = np.sum(self.mass[elements[elements>=0]])
            self.center_of_mass[self.nbodies + i] = np.sum(self.center_of_mass[elements[elements>=0]]*self.mass[elements[elements>=0], np.newaxis], axis=0)
            self.center_of_mass[self.nbodies + i] /= self.mass[self.nbodies + i]
        # print('mass', self.mass)
        # print('center_of_mass', self.center_of_mass)

    def computeForce(self, p):
        return pythran_functions.computeForce(self.nbodies, self.child, self.center_of_mass, self.mass, self.cell_radius, p)

    def __str__(self):
        indent = ' '*2
        s = 'Tree :\n'
        for i in range(self.ncell+1):
            s += indent + 'cell {i}\n'.format(i=i)
            cellElements = self.child[self.nbodies + 4*i:self.nbodies + 4*i+4]
            s += 2*indent + 'box: {min} {max} \n'.format(min = self.cell_center[i]-self.cell_radius[i], max = self.cell_center[i]+self.cell_radius[i])
            s += 2*indent + 'particules: {p}\n'.format(p=cellElements[np.logical_and(0<=cellElements, cellElements<self.nbodies)])
            s += 2*indent + 'cells: {c}\n'.format(c=cellElements[cellElements>=self.nbodies]-self.nbodies)
            
        return s
