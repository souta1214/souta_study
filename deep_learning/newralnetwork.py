from sys import _xoptions
import numpy as np

#バイアスと活性化関数は省略
X = np.array([1,2])
print(X)
print(X.shape)
W = np.array([[1,3,5],[2,4,6]])
print(W)
print(W.shape)
Y = np.dot(X,W)
print(Y)
Z = np.array([3,4])

#pythonの引数における参照渡しと値渡しについて
#値渡しとは，関数を呼び出す時に仮引数に指定した値をコピーして実引数に渡す方式
#pythonでは関数を呼び出すときに引数をしてすると参照渡しが使用される
def array_fun(X,Z):
    Y = X + Z
    return Y

array_fun(X,Z)
print(array_fun(X,Z))


