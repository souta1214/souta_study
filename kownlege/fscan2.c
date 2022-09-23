/* write_name_age.c */
#include <stdio.h>

int main()
{
    FILE* fp;
    char name[51];
    int age;

    printf("名前を入力してください。\n");
    scanf("%s", name);
    printf("年齢を入力してください。\n");
    scanf("%d", &age);

    fp = fopen("memo3.txt", "w");    /* 書き出し用にファイルを開く */
    if(fp == NULL) return 1;

    //第一引数にfpを入れることを除くとprintfと同じ
    fprintf(fp, "%s\n", name);       /* nameをファイルに書き出す */
    fprintf(fp, "%d\n", age);         /* ageをファイルに書き出す */

    fclose(fp);
    return 0;
}