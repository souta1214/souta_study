import numpy as np
import matplotlib.pyplot as plt

def function_2(x):
    return x[0]**2 + x[1]**2
    #return np.sum(x**2)        

x = np.arange(-3,3,1)
y = function_2(x)
#plt.xlabelの複数指定の方法
plt.xlabel("x0","x1")
plt.ylabel("f(x)")
plt.plot(x, y)
plt.show()

#偏微分の場合は，変数が一つだけの関数を定義して，その関数についての微分を求める形にしている
