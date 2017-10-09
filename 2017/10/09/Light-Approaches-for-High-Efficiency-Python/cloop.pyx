import numpy as np
cimport numpy as np
import cython

@cython.boundscheck(False)
@cython.wraparound(False)
cdef double _sum2d(np.ndarray[np.float32_t, ndim=2] arr):
    cdef int n, m
    n = arr.shape[0]
    m = arr.shape[1]
    cdef double ret = 0.0
    for i in range(n):
        for j in range(m):
            ret += arr[i, j]
    return ret

def sum2d(arr):
    return _sum2d(arr)

