# import numpy as np
import sys, os
import numpy as np
from dataset.mnist import load_mnist
#画像の表示に使用するモジュールPIL
from PIL import Image

def img_show(img):
    #配列オブジェクトを入力として受け取り，その配列オブジェクトから作成した画像オブジェクトを返す
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()

(x_train, t_train),(x_test, t_test) = load_mnist(normalize = False, flatten = True)
img = x_train[0]
label = t_train[0]
print(label)

#(784,)
print(img.shape)
#形状をもとのサイズに変換する
img = img.reshape(28, 28)
print(img.shape)

img_show(img)

#appendとは，リストに要素を追加するためのメソッド
#insertとは，appendの最後にのみ付加するとは違い，追加したい位置を指定して，追加できる（a.insert(2, 2.5)）
#extendとは，リストを結合させたいときに使用するメソッド
