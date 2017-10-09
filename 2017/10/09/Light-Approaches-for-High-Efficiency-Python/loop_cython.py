import numpy as np
import cython
import cloop

if __name__ == "__main__":
    test = np.arange(100000000).reshape(1000, 100000).astype(np.float32)
    print (cloop.sum2d(test))
