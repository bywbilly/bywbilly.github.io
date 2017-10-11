import multiprocessing
import numpy as np

def f(x):
    return x + 1

if __name__ == "__main__":
    cores = multiprocessing.cpu_count()
    pool  = multiprocessing.Pool(processes=cores)

    x = np.arange(100000000)
    y = pool.map(f, x)
