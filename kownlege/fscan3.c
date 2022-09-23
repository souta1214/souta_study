/* read_name_age.c */
#include <stdio.h>

int main()
{
    FILE* fp;
    char name[51];
    int age;

    fp = fopen("memo2.txt", "r");    /* 読み込み用にファイルを開く */
    if(fp == NULL) return 1;

    fscanf(fp, "%s", name);         /* ファイルから読み込んだ文字列をnameに格納 */
    fscanf(fp, "%d", &age);         /* ファイルから読み込んだ整数をageに格納 */

    printf("名前： %s\n", name);
    printf("年齢： %d\n", age);

    fclose(fp);
    return 0;
}