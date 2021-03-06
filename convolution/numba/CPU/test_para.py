import os
#os.environ["NUMBA_DUMP_IR"] = "1"
#os.environ["NUMBA_DUMP_OPTIMIZED"] = "1"
#os.environ["NUMBA_DUMP_ASSEMBLY"] = "1"
import time
import numpy as np
import numba
from numba import float64 
import concurrent.futures
import threading

nthreads = 4

@numba.njit(nogil=True, parallel=False)
def axpy(a, x, y):
    for i in range(x.size):
        y[i] = a*np.exp(x[i] + y[i])

def make_singlethread(inner_func):
    """
    Run the given function inside a single thread.
    """
    def func(*args):
        inner_func(1, *args)
    return func

def make_multithread(inner_func, numthreads):
    """
    Run the given function inside *numthreads* threads, splitting its
    arguments into equal-sized chunks.
    """
    def func_mt(*args):
        length = len(args[0])
        chunklen = (length + numthreads - 1) // numthreads
        # Create argument tuples for each input chunk
        chunks = [[arg[i * chunklen:(i + 1) * chunklen] for arg in args]
                  for i in range(numthreads)]
        # with concurrent.futures.ThreadPoolExecutor(max_workers=nthreads) as executor:
        #     future_to_axpy = {executor.submit(inner_func, 1, *chunk): chunk for chunk in chunks}
        #     for future in concurrent.futures.as_completed(future_to_axpy):
        #         future.result()
                
        # Spawn one thread per chunk
        threads = [threading.Thread(target=inner_func, args=[1] + chunk)
                   for chunk in chunks]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        # return result
    return func_mt

x = np.arange(10**6)
y = np.ones(10**6)

func1 = make_singlethread(axpy)
func1(x, y)
nrep = 10
t1 = time.time()
for i in range(nrep):
    func1(x, y)
t2 = time.time()
print("serial: ", (t2-t1)/nrep)

func = make_multithread(axpy, nthreads)
func(x, y)
nrep = 10
t1 = time.time()
for i in range(nrep):
    func(x, y)
t2 = time.time()
print("serial: ", (t2-t1)/nrep)

#print(np.all(x + 1 == y))
# @numba.guvectorize([(float64[:], float64[:], float64[:])], '(n),(n)->(n)', nopython=True, target='parallel')
# def test_para_2(x, y, z):
#     z = x + y
#     # for i in range(x.size):
#     #     z[i] = x[i] + y[i]

# @numba.vectorize([float64(float64, float64)], nopython=True, target='parallel')
# def vec_add(x, y):
#     return x + y

# @numba.njit(nogil=True, parallel=False)
# def test_serial(x, y, z):
#     for i in range(x.size):
#         z[i] = x[i] + y[i]


# @numba.njit(parallel=True)
# def test_para_2d(a, x, y):
#     for i in range(x.shape[0]):
#         for j in range(x.shape[1]):
#             y[i, j] = a*x[i, j] + y[i, j]

# @numba.njit(nogil=True, parallel=False)
# def test_serial_2d(a, x, y):
#     for i in range(x.shape[0]):
#         for j in range(x.shape[1]):
#             y[i, j] = a*x[i, j] + y[i, j]
        
# x = np.zeros(1000000)
# y = np.zeros(1000000)
# z = np.zeros(1000000)
# a = 1
# test_serial(x, y, z)

# test_para_1(x, y, z)
# test_para_2(x, y, z)
# vec_add(x, y)

# nrep = 1000
# t1 = time.time()
# for i in range(nrep):
#     test_serial(x, y, z)
# t2 = time.time()
# print("serial: ", (t2-t1)/nrep)

# t1 = time.time()
# for i in range(nrep):
#     test_para_1(x, y, z)
# t2 = time.time()
# print("para 1: ", (t2-t1)/nrep)

# t1 = time.time()
# for i in range(nrep):
#     test_para_2(x, y, z)
# t2 = time.time()
# print("para 2: ", (t2-t1)/nrep)

# t1 = time.time()
# for i in range(nrep):
#     z = vec_add(x, y)
# t2 = time.time()
# print("para 2: ", (t2-t1)/nrep)

# x = np.zeros((1000, 10000))
# y = np.zeros((1000, 10000))

# t1 = time.time()
# for i in range(100):
#     test_serial_2d(1, x, y)
# t2 = time.time()
# print("serial 2d: ", t2-t1)

# t1 = time.time()
# for i in range(100):
#     test_para_2d(1, x, y)
# t2 = time.time()
# print("para 2d: ", t2-t1)
