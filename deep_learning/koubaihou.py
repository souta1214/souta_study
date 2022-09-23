#勾配法とは，各地点の勾配方向に繰り返し進むことで，関数の値を徐々に減らしていける
#学修率は，逐一確認して最適化していく

#lrはleraning rate
#極小値をもとめられ，うまくいけば最小値を！
#学修率のようなパラメータをハイパーパラメータという．これは，
# ニューラルネットワークのパラメータ（バイアス，重み）とは性質が異なり手動
def gradient_descent(f, init_x, lr = 0.01, step_num = 100):
    x = init_x

    for i in range(step_num):
        grad = numerical_gradient(f, x)
        x -= lr * grad

    return x

#def f(x):...ではなく簡単な処理の場合は，lambdaという記法を使用することもある
#f = lambda w: net.loss(x ,t)