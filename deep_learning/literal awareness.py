#MNISTデータセットのダウンロードから画像データのNumpy配列への変換までをサポートするスクリプト(mnist.py)
#osモジュールとは，pythonのコード上でOSに関する操作をするためのもの
#ファイルパスの設定には，sysとosのライブラリを利用する
import sys, os
#sys.path.apppend()はリストに新たなパスを追加するということ
#引数として渡すos.pardirは親ディレクトリを示している（親ディレクトリのファイルをインポートするための設定）
#os.pardirは，作業フォルダの親フォルダの代名詞として働く
# sys.path.append('..//deep-learning-from-scratch-master')
#相対パスでインポートする方法
from dataset.mnist import load_mnist

#load_mnist関数は，「訓練画像，訓練ラベル」，「テスト画像，テストラベル」
# という形式で，読み込んだMNISTデータを返す
#また，引数として三つ設定できる
#一つ目のnormalizeは，入力画像を0.0～1.0の値に正規化するかどうかを設定する（Falseにすれば入力画像のピクセルは0～255のまま）
#二つ目のflattenは，入力画像を滑らかにする（一次元配列にする）
#↑Falseに設定すると，入力画像は1×28×28の三次元配列として，Trueにすると784個の要素からなる一次元配列として格納される
#三つ目のone_hot_labelは，labelをone_hot表現として格納するかを設定する．
#one_hot表現とは，[0,0,1.0,1,0,0,0]のように，正解となるlabelのみが1でそれ以外が0の配列．
(x_train, t_train), (x_test, t_test) = load_mnist(flatten=True, normalize=False)

#それぞれのデータの形状を出力
print(x_train.shape)
print(t_train.shape)
print(x_test.shape)
print(t_test.shape)

#picklファイルとは，
#正規化する理由とは，
#滑らかにするとは，
