import os, sys
#現在作業しているフォルダを取得
print(os.getcwd())
sys.path.append('C:\Users\souta\github_code\deep-learning-from-scratch-master\dataset')
from dataset.mnist import load_mnist