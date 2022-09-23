#include<stdio.h>
#include<stdlib.h>

//構造体宣言
//typedefを使用するとすでにあるデータ型に新しい名前を付けることができる
//typedef 既存のデータ　新しいデータ;

typedef struct{
    int num;
    char *str;
} strct;

int main(void){
    strct *entity;

    //動的メモリの確保
    //sizeof演算子とは，変数の型のメモリサイズを調べるための演算子，バイト単位で返してくれる
    entity = (strct*)malloc(sizeof(strct));

    //メンバーの初期化
    entity->num = 0;
    entity->str = (char*)malloc(sizeof(char) * 32);

    //メモリに文字列を代入
    //sprintf関数は書式付き文字列を文字配列に格納する
    sprintf(entity->str, "%s %s!", "HELLO", "WORLD");
    printf("%d", sprintf);
    printf("%s\n", entity->str);
    printf("%p\n", &entity->str);
    printf("%d",1);

    //メモリの解散
    free(entity->str);
    free(entity);

    return 0;
}

