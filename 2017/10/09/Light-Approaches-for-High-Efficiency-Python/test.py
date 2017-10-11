import multiprocessing

def init():
    global tf
    global sess
    import tensorflow as tf
    config = tf.ConfigProto()
    config.gpu_options.allow_growth=True
    sess = tf.Session(config=config)

def hello(name):
    return sess.run(tf.constant('hello ' + name))

if __name__ == '__main__':
    pool = multiprocessing.Pool(processes=2, initializer=init)
    xs = ['world', 'abcdabcd987', 'Lequn Chen']
    print pool.map(hello, xs)