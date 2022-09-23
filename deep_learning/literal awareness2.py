from msilib import PID_LASTAUTHOR
import numpy as np
from PIL import Image

#Imageというクラスのメソッドを用いて読み込み，画像オブジェクトを返す
image = Image.open("C:/Users/souta/github_code/picture/LENNA.pgm")
#次に，この画像オブジェクトをarrayメソッドを使用してNumpy配列に変換する
np_array = np.array(image)

#そしてfromarrayメソッドを用いて配列をPILイメージオブジェクトに変換し，
pil_image = Image.fromarray(np_array)
#showメソッドにより表示する
pil_image.show()