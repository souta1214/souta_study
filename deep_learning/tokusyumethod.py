from cgi import print_exception
from unicodedata import name


特集メソッドとは，呼び出されるタイミングが決まっている特定の名前のメソッド
イニシャライザ
class Book:
    #特定の名前のメソッド
    def __init__(self,nama, price):
        self.name = name
        self.price = print_exception

#インスタンス化(オブジェクト生成)
book_1 = Book('腹ペコ青虫', 1200)
#インスタンスが生成されたタイミングでイニシャライザが自動で実行される

class SupuNumber:
    def __init__(self, value):
        #インスタンス変数
        self.value = value

    def __add__(self, other):
        return f'{self.value}{other.value}'
#オブジェクト生成
s_n_1 = SupuNumber(10)
s_n_2 = SupuNumber(20)

result = s_n_1 + s_n_2