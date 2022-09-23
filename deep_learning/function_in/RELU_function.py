import numpy as np
import matplotlib.pylab as plt

def RELU_function(x):
    return np.maximum(0,x)

x = np.arange(-5.0, 5.0, 0.1)
y = RELU_function(x)

plt.plot(x,y)
#y軸の範囲を指定
plt.title("RELU_function")
plt.ylim(-0.1, 1.1)
plt.show()