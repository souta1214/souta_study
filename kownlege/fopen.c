//ファイルの扱いについて
// #include<stdio.h>

/* constとは、変数の値を変更せず定数として宣言する際に使う修飾子です。
constが付くと変数は書き換えができなくなり、読み取り専用となります。
値を変更しようとするとコンパイルエラーが発生します。 */
// FILE * fopen(const char * filename, const char * mode);
// errno_t fopen_s(FILE ** fp, const char * filename, const char * mode);
//fopen関数は（ファイルハンドル）fopen(開きたいファイルの名前,開くときのモード)
//ファイルハンドルとは，ファイルを操作するためのハンドル（一つのファイルに対して，一つ紐づく）
//バイナリファイルとはコンピュータにとっては意味があるものの，中身がバイナリデータであるために，人間が読めない
//rb,wbなどで指定できる

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main (void)
{
    //ファイルハンドルを管理するための変数には，FILE構造体をポインタ変数で用意する
    //int * fp = 0;みたいな感じ
    FILE * fp = NULL;
    //この場合作業ディレクトリに作成される
	//fopen関数はアドレスを出力する（ファイルハンドル）
    fp = fopen("memo.txt", "w");

    //fclose(閉じるべきファイルハンドル(fp))
    fclose(fp);
    return 0; 
}

//ヒープ領域とは，動的に確保と解法を繰り返すことのできるメモリ領域のこと
//プログラム実行時には，OSからソフトウェアに対して一定量のヒープ領域が与えられる
//データの仮置き場，臨時の作業台
//stack領域と異なる点はstack領域は最後に確保した順に開放するのに対して，任意の順で解法・確保する

//fopen_sとはfopenのセキュア版
//fopenとは異なり第一引数には，ファイルハンドルへのポインタ
// セキュア版である「fopen_s関数」では、書き込みモードで同一ファイルを同時にオープンすることを禁止しています。
// そのため次のプログラムは、２回目の呼び出しで異常終了します。
// #include <stdio.h>
/* 
int main(void)
{
	FILE * fp = NULL;
	errno_t no;

	no = fopen_s(&fp, "memo.txt", "w");
	if (no != 0)
	{
		printf("ERR(%d):ファイルのオープンに失敗しました", no);
	}

	fclose(fp);

	return 0;
} */