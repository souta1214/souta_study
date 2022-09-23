#数値微分とは，プログラムで極限を扱うことができないので，
# hに十分小さい値を入れることで微分係数を近似するもの
#だが，あまりにも小さすぎると，丸め誤差が起きる（h = 10^-4）

from operator import le
import numpy as np
import matplotlib.pylab as plt

#中心差分
def numerical_diff(f,x):
    #0.0001
    h = le-4
    return (f(x + h) - f(x - h)) / (2*h)

def function_1(x):
    return 0.01*x**2 + 0.1*x

x = np.arange(0.0, 20.0, 0.1)
y = function_1(x)
plt.xlabel("x")
plt.ylabel("f(x)")
plt.plot(x, y)
plt.show()

#コンソールとは，コンピュータと意思疎通をする際に使用するもの（キーボード，ディスプレイなど）
