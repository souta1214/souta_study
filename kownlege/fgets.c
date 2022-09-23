/* fgets関数は，第一引数に読み取った文字列を格納するためにこちら側で用意する配列，
第二引数は一度に読み込む文字数の数，（一番後ろにはNULL文字を付けて返すので，一度に読み込む文字はー１されると考える）
第三引数はオープンされたファイルポインタを */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp = fopen("memo3.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "file not opened");
  }
  char *buffer = malloc(sizeof(char) * 6);
  while (fgets(buffer, 6, fp) != NULL) {
    printf("%s\n", buffer);
  }
//   free関数とはmalloc,realloc,callocのような関数により確保されたメモリを開放する関数
//上記の関数はすべて動的にメモリを確保する関数．
//メモリを確保すれば，そのメモリは自身のプログラムで自由自在に扱うことができる，そのメモリが他のプログラムによって利用されることもない
//まあ少なくとも，電源を切ればメモリはリセットされる
  free(buffer);
  fclose(fp);
  return 0;
}

/* 結局どれがベストなのでしょう？

fgetcは一文字ずつ読みこみたい時。
fgetsは改行区切りで読みこみたい時。 atoi関数などもそのまま使えて便利です。
fscanfは型の異なるデータがカンマ区切りやスペース区切りで並んでいて、それが複数行にわたる時。
freadはバイナリファイルや構造体などがデータの時。 */