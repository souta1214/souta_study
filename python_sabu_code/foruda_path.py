from subprocess import _TXT


# ディレクトリ＝フォルダ

# 相対パス
# ./dir/B.txt (.はカレントディレクトリ)

# 一つ下の階層→./フォルダ名
# 一つ上の階層→../

# パス操作モジュール
# os,glob（パターンマッチ，再帰的な操作）,pathlib（パスオブジェクトを使用する）などがある
#pathlibのメリットはリスト内包表記（つなげて書くことができる）

# amoid.py
def a_method():
    pass
a_var = None

# importとは，別のファイル（モジュール）に記述されたpythonコードを取り込む機能のこと
# そうすることで，module.methodやmodule.variableのような記述が可能になり，モジュールのメソッドや変数を参照できるようになる
# そして，from module import methodやfrom module import variableという記載を用いることで，モジュール名を省略することができる
#from amod import *により，モジュール内で定義されたメソッド屋変数をまとめてインポートできる
#a_method()
#a_var

from pathlib import Path
#Pathオブジェクトを生成（ファイルに対しても作れる）
path = Path('/home/dir1')
#pathオブジェクトiterdir関数からジェネレータを取得
dir_g = path.iterdir()
p_list = list(dir_g)
for x in dir_g:
    print(x)
    #print(str(x)),()

#カレントディレクトリの取得
path = Path.cwd
#Path結合したPathオブジェクト
path_c = path/'dir1'
#ファイル名・ディレクトリ名
path_c.name

#リスト内包表記
paths = [str(x) for x in dir_g]

#ファイルかディレクトリかを判断する（True,False）
path.is_file()
path.is_dir()
#実際に存在するか？
path.exist()

#再帰的に取得(下の階層にまで潜って取得する)
g = path.glob('**/*.py などの指定もできる')
for x in g:
    print(x)


#ファイルの作成・削除
path = Path('/home/file.txt')
path.touch(exist_ok=True)
path.unlink(missing_ok=True)

#ディレクトリの作成・削除
path.mkdir()
path.rmdir()
