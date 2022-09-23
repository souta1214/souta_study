# 機械学習の問題は「分類問題」と「回帰問題」に大別できる
# 分類問題とは，データがどのクラスに属するか（ソフトマックス関数）
# 回帰問題とは，ある入力データから（連続的な）数値の予測を行う（恒等関数）

import numpy as np

#ソフトマックス関数の実装
#指数を扱う計算なのでオーバーフローに注意する必要がある
def softmax_function(a):
    #オーバーフロー対策
    c = np.max(a)
    exp_a = np.exp(a - c)
    sum_exp_a = np.sum(exp_a)
    y = exp_a / sum_exp_a

    return y

