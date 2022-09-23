# coding: utf-8
import sys, os
sys.path.append(os.pardir)  # 親ディレクトリのファイルをインポートするための設定
import numpy as np
import pickle
from dataset.mnist import load_mnist
from common.functions import sigmoid, softmax


def get_data():
    (x_train, t_train), (x_test, t_test) = load_mnist(normalize=True, flatten=True, one_hot_label=False)
    return x_test, t_test


def init_network():
    #pklファイルには重みとバイアスのパラメータがディクショナリ型の変数として保存されたいる
    with open("deep-learning-from-scratch-master\ch03\sample_weight.pkl", 'rb') as f:
        network = pickle.load(f)
    return network


def predict(network, x):
    W1, W2, W3 = network['W1'], network['W2'], network['W3']
    b1, b2, b3 = network['b1'], network['b2'], network['b3']

    a1 = np.dot(x, W1) + b1
    z1 = sigmoid(a1)
    a2 = np.dot(z1, W2) + b2
    z2 = sigmoid(a2)
    a3 = np.dot(z2, W3) + b3
    y = softmax(a3)

    return y

#xは実際試験する問題,tはxの解答
x, t = get_data()
network = init_network()

#バッチ数
batch_size = 100

accuracy_cnt = 0
#xに格納された画像データを一枚ずつ分類
#len関数は，リストや辞書のサイズを取得する
#range関数は(start,end,step)のような書き方でstartからend-1までの整数からなるリストを作成する
#さらに，リストの要素の次の値がstepで指定された値だけ増加するリストを作成
for i in range(0, len(x), batch_size):
    #x[0:100],x[100:200]の順で作成していく
    x_batch = x[i:i+batch_size]
    y_batch = predict(network, x_batch)
    #axsis = 1により，100×10の配列の中で一次元目の要素ごとに，最大値のインデックスを求める
    p = np.argmax(y_batch, axis=1)
    accuracy_cnt += np.sum(p == t[i:i+batch_size])


    # y = predict(network, x[i])
    # 最も確率の高い要素のインデックスを取得（引数に与えられた配列の要素の中から最大の値を取得）
    # p= np.argmax(y) 
    # if p == t[i]:
        #正解した割合を認識精度としている
        # accuracy_cnt += 1

print("Accuracy:" + str(float(accuracy_cnt) / len(x)))

#そもそもなぜ正規化するのか？
#端的に言うと，いろんな単位のデータを入力としてディープラーニングで学習させるより，
# 共通の尺度で統一された値を入力データとして与えた方が精度がいい学習モデルができるから
