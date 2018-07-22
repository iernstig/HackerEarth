from matplotlib import pyplot as plt
import numpy as np
import math

def log_n(val, base):
    return np.log(val)/np.log(base)

if __name__ == '__main__':
    x = np.arange(1, 100)
    y2 = log_n(x, 2)
    y3 = log_n(x, 3)
    y100 = log_n(x, 100)
    plt.plot(x, y2, color="r")
    plt.plot(x, y3, color="b")
    plt.plot(x, y100, color="g")
    plt.show()
