from tkinter import Y
import numpy as np
import matplotlib.pylab as plt


#ディクショナリがリストと異なる点としては，リストは添え字でデータ管理を行うが，ディクショナリは文字列であるキーで行う
#ディクショナリの基本構造は以下の通り
#ディクショナリ名　= {キー値，キー値，．．．}

#シグモイド関数
def sigmoid_function(x):
    return 1/(1 + np.exp(-x))

x = np.arange(-5.0, 5.0, 0.1)
y = sigmoid_function(x)

plt.plot(x,y)
#y軸の範囲を指定
plt.title("sigmoid_function")
plt.ylim(-0.1, 1.1)
plt.show()

#恒等常関
def identity_function(x):
    return x

#重みとバイアスの初期化，それらをディクショナリ型の変数networkに格納する
def init_network():
    network = {}
    network['W1'] = np.array([[0.1, 0.3, 0.5],[0.2, 0.4, 0.6]])
    network['b1'] = np.array([[0.1, 0.2, 0.3]])
    network['W2'] = np.array([[0.1, 0.4],[0.2, 0.5],[0.3, 0.6]])
    network['b2'] = np.array([[0.1, 0.2]])
    network['W3'] = np.array([[0.1, 0.3],[0.2, 0.4]])
    network['b3'] = np.array([[0.1, 0.2]])

    return network

#入力信号が出力信号に変換されるプロセスをまとめている
def forward(network, x):
    #変数の宣言
    W1, W2, W3 = network['W1'], network['W2'], network['W3']
    b1, b2, b3 = network['b1'], network['b2'], network['b3']

    a1 = np.dot(x, W1) + b1
    z1 = sigmoid_function(a1)
    a2 = np.dot(z1, W2) + b2
    z2 = sigmoid_function(a2)
    a3 = np.dot(z2, W3) + b3
    y = identity_function(a3)

    return y

network = init_network()
x = np.array([1.0, 0.5])
y = forward(network,x)
print(y)

