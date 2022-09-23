リスト内包表記→リストを簡単に生成するための表記で，forを使って一行で書ける
１．forの繰り返し処理だけで作成
x = []
for i in range(11):
    x.append(i)
２．
[i for i in range(11)]
（一般式）
[式for 変数in繰り返しオブジェクト]
（具体例）
names = ['斎藤'，'山田'，'田中']
x = [i + 'さん' for i in namas]
print(x)

３．
（条件付き）
[i for i in range(11) if i % 2 == 0(条件式がtureの時だけ要素を追加)]
（具体例）
foods = ['apple','banana','lemon']
x = [i for i in foods if 'a' in i]
print(x)

４．
（三項演算子）
['ぐ'(True)if i%2 == 0 else i(False)(←三項演算子) for i in range(11)]