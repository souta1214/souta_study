/* 文字列型のデータを数値型のデータのように「＝」記号を使って代入コピーしようとしても，
配列の場合は代入出来なかったり，ポインタの場合はアドレス先をコピーすることになるなど */

/* 配列の場合は変数の場合と同様のほか，「配列名だけだと，その配列の先頭要素のアドレスを示す」
つまり，data == &data[0] */
#include <stdio.h>
 
int main(void) {
    char str1[16] = "Hello World!";
    char str2[16];
    
    /* 配列の代入は不可
    str2 = str1;
    */
    
    char *ptr1, *ptr2;
    ptr1 = str1; // char型ポインタにchr型配列のアドレスを代入
    
    // 文字列のアドレスのコピー(浅いコピー)
    ptr2 = ptr1;
    printf("ptr2の文字列は: %s\n", ptr2);
    printf("ptr1のアドレス: %p, ptr2のアドレス: %p\n", ptr1, ptr2);
    
    str1[0] = 'h'; 
    printf("ptr1の文字列は: %s\n", ptr1);
    printf("ptr2の文字列は: %s\n", ptr2);
    
    return 0;
}

// strcpy関数はヘッダーファイル「string.h」をインクルードして使用します。
//strcpyの第1引数にはコピー先のアドレス、第2引数にはコピー元のアドレスを記入します。
#include <stdio.h>
#include <string.h>
 
int main(void) {
    char str1[16] = "Hello World!";
    char str2[16];
    
    // 文字列のコピー
    strcpy(str2, str1);
    printf("str2の文字列は: %s\n", str2);
    
    return 0;
}