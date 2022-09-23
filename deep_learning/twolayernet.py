#確率的勾配降下法
#二層のニューラルネットワークを，一つのクラスとして実装する

import numpy as np
from dataset.mnist import load_mnist
from function_in.sigmoid_function import sigmoid_function
from function_in.softmax_function import softmax_function
from code.koubai import numerical_gradient


#paramsはニューラルネットワークのパラメータを保持するディクショナリ変数（インスタンス変数）
#gradsは勾配を保持するディクショナリ変数（メソッドの戻り値）
class TwoLayerNet:
    #ハイパーパラメータ
    #weight_init_stdは重みを小さな値にして過学習を抑える
    def __init__(self, input_size, hide_size, output_size, weight_init_std = 0.01):


    def predict(self, x):

        
    def loss(self, x, t):


    def accuracy(self, x, t):


    def numerical_gradient(self, x, t):


    
