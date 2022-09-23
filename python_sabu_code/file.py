# ファイルオブジェクトを作製することでファイル操作ができる
# f = open(ファイルパス，モード)
# モード: 'r','w（ないと新しく作る）','a（追記）','r+'などがある

#withを使用することでcloseの操作をしなくても，withの中を抜けると勝手にファイルがcloseする
with open(ファイルパス，モード) as 変数名（←ファイルオブジェクトが代入される，一般的にはfがよく使われる）:
    #fファイル操作

with open(ファイルパス) as f:
    #ファイルオブジェクトのreadメソッドにより，ファイルの内容を文字列で取得できる
    s = f.read()
    #readlineメソッドは一行毎に取得
    #readlinesメソッドはすべてをリストで読み込む

with open(ファイルパス) as f:
#with open(ファイルパス，'a') as f:でデータの追記，このように第二引数にモードをしていることで    
    f.write(書き込みたい文字列)

#writelinesを使用することでリストを書き込むことができる
x = ['a','b','c']
with open(ファイルパス,'w') as f:
    f.writelines(x)

#joinメソッドは，リストの各間に指定のものを入れて，一つも文字列に結合するもの
x_list = ['apple','orage','banana']
s = '\n'.join(x_list)

with open('test3.txt', 'w') as f:
    f.write(s)
    