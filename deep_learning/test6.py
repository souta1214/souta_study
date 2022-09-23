import os, sys
#現在作業しているフォルダを取得
print(os.getcwd())
sys.path.append(os.pardir)
print(sys.path.append(os.pardir))
#os.pardirは，作業フォルダの親フォルダの代名詞として働く
