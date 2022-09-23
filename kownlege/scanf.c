//scanfの基本文法
//scanf("入力変換指定子",変数の場所);
//変数の場所とは，普通の変数名の前に＆をつけることで表現できる（ポインタ変数の前にはつけなっくてよい）
#include<stdio.h>

int main (void){
    int a;
    long f;
    
    printf("fの値を入力して下さい.\n");
    scanf("%ld",&f);
    //入力した値の表示
    printf("f = %d",f);
    scanf("%d", &a);

    printf("%d", a);
    return 0;

}
//Ctrl+shift+@でターミナル起動