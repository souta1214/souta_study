#すべての変数の偏微分をベクトルとしてまとめたものを，勾配という．
#勾配の方向は，各場所において関数の値を最も減らす方向

from operator import le
import numpy as np


def numerical_gradient(f ,x):
    h = le-4
    #xと同じ形状の配列を生成(配列の要素すべて0)
    grad = np.zeros_like(x)

    for idx in range(x.size):
        tmp_val = x[idx]
        #f(x+h)の計算
        x[idx] = tmp_val + h
        fxh1 = f(x)

        #f(x-hの計算)
        x[idx] = tmp_val - h
        fxh2 = f(x)

        grad[idx] = (fxh1 - fxh2) / (2*h)
        #値を元に戻す
        x[idx] = tmp_val

    return grad