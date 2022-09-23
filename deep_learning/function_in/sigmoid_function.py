import numpy as np
import matplotlib.pylab as plt

def sigmoid_function(x):
    return 1/(1 + np.exp(-x))

x = np.arange(-5.0, 5.0, 0.1)
y = sigmoid_function(x)

plt.plot(x,y)
#y軸の範囲を指定
plt.title("sigmoid_function")
plt.ylim(-0.1, 1.1)
plt.show()

#なぜ活性化関数が必要なのか？またなぜ非線形なのか？
#結論としては，「モデルがスケールを獲得し，表現力が豊かになる」
#以下に詳細

