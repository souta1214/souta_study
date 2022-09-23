import numpy as np
import matplotlib.pylab as plt

def step_function(x):
    return np.array(x > 0, dtype=np.int)

x = np.arange(-5.0, 5.0, 0.1)
y = step_function(x)

plt.plot(x,y)
#y軸の範囲を指定
plt.title("step_function")
plt.ylim(-0.1, 1.1)
plt.show()

#ply.plot（x,y,alpha=0.5(透明度),color='r'(グラフの色を指定),
# label='test'(凡例を付ける),linestyle='--'(線の種類を指定する),linewidth=10(線の種類を指定する)）