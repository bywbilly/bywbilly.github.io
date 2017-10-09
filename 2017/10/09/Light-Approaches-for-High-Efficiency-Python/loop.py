import numpy as np

def sum2d(arr):
    n, m = arr.shape
    ret = 0.0
    for i in xrange(n):
        for j in xrange(m):
            ret += arr[i, j]
    return ret

if __name__ == "__main__":
    test = np.arange(100000000).reshape(1000, 100000)
    print (sum2d(test))
