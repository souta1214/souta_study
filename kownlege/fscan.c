/* ファイルの書き込みにfprintf関数があるように、ファイルの読み込みにはfscanf関数(fscanf_s関数)があります。
ファイルから文字列を読み込んで変数に値を格納する場合には、fgetc関数やfgets関数よりもfscanf関数を利用したほうが便利なことがあるので紹介します。
 */

#include <stdio.h>
#include <time.h>

void Read(const char *file)
{
    //ファイルポインタ
    FILE *fp;

    //fopenはファイルを開くことに失敗した場合，NULLを返す
    //fp = fopen(file, "r");
    fopen_s(&fp, file, "r");
    if (fp == NULL)
    {
        printf("初回の起動です。\n");
        return;
    }

    int year, mon, day, hour, min, sec;
    fscanf_s(fp, "%d%d%d%d%d%d",
        &year, &mon, &day,
        &hour, &min, &sec
    );

    printf("前回の起動日時\n");
    printf("%04d/%02d/%02d %02d:%02d:%02d",
        year, mon, day,
        hour, min, sec
    );

    fclose(fp);
}

void Write(const char *file)
{
    FILE *fp;
    time_t t;
    time(&t);
    struct tm local;
    localtime_s(&local, &t);

    //fp = fopen(file, "w");
    fopen_s(&fp, file, "w");
    if (fp == NULL)
    {
        printf("%sのオープンに失敗しました。\n", file);
        return;
    }

    fprintf(fp, "%d %d %d %d %d %d",
        local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
        local.tm_hour, local.tm_min, local.tm_sec
    );

    fclose(fp);
}

int main()
{
    const char *file = "C:\\test.txt";

    Read(file);
    Write(file);

    getchar();
}