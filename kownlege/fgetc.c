#include <stdio.h>
#include <stdlib.h>

//この例からもわかる通り、fgetcはファイルの先頭を指すポインタfpを受け取って一文字出力し、そのあと関数の内部で指している文字を一分進めていることが分かります。
int main (void)
{
    FILE *fp = fopen("memo3.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "file not opened");
    }
    int c;
    //EOFとは、getcharを使うのであれば、ファイルの末端まで読んだことを示す「ファイル終了のお知らせ」です。
    while((c = fgetc(fp)) != EOF){
        printf("%c %d\n", c,c);
    }

    //最後に出力される10はASCLLのLF，つまり改行コードを表す
    fclose(fp);
    return 0;

}