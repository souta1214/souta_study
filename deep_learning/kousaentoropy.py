#データが一つの場合と，バッチとしてまとめられて入力される場合の両方のケースに対応する実装をする
import numpy as np


def cross_entropy_error(y, t):
    if y.ndim == 1:
        #sizeは行列の全要素数を求める
        #reshape(一次元目のサイズ，二次元目のサイズ，．．．)
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)
    
    batch_size = y.shape[0]
    return -np.sum(t * np.log(y + le-7)) / batch_size



#darrayクラスは，型や整列のされ方が統一された数値の入れ物（pythonのリストではなく，独自のデータ構造を演算に使用する）
#ndimとは，多次元配列が何次元の構造をしているかを見る．(len(arr.shape))(shapeの要素の数)

#教師データがone_hot表現ではなく，ラベルとして与えられたとしたら
def cross_entropy_error(y, t):
    if y.ndim == 1:
        #sizeは行列の全要素数を求める
        #reshape(一次元目のサイズ，二次元目のサイズ，．．．)
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)
    
    batch_size = y.shape[0]
    #np.arange(batch_size)は0から，batch_size-1までの配列を生成する→[1,2,3,....,batch_size-1]
    return -np.sum(t * np.log(y[np.arange(batch_size), t] + le-7)) / batch_size
    #[y[0,2], y[1,7], y[2,0], y[3,9], y[4,4]]のような配列が生成される

