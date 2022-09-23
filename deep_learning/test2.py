import matplotlib.pyplot as plt
from matplotlib.image import imread

#画像ファイルを読み込むときはimreadメソッドを使用する
#第一引数は「画像へのパス」，第二引数は「（省略可能）画像ファイルの読み込みモードを指定する」
img = imread('C:/Users/souta/github_code/picture/LENNA.pgm')
#画像表示のための
plt.imshow(img)

plt.show()
