/* ポインタとは，アドレスを指し示す仕組み（ショートカット）
・別の関数から値にアクセスるため
・複数の戻り値を返す
・配列にアクセスするため
・データ構造を作るため（きれいな（二分木，ハッシュ））

メモリIC
・変数や関数・配列・int apple = 10;などは0,1の電気信号（電気のon,off）に変換されてメモリへ

ポインタはアドレスしか持てない（数値はない）
ポインタとは、変数のアドレスを記憶する変数のことでした。
ポインタに＊を付けると，それが示す先のものを示す */
// int*p;

/* #include <stdio.h>

int main (void){
    int apple = 10;
    int *p;
    p = &apple; //appleの住所をpそれ自体に代入できた
    printf("%d" , *p);  //数値出力
    printf("%p" , p);
}
 */
// ポインタを使って，別の場所から値を操作する(swap関数を使ったりする)
/* #include <stdio.h>

void keisan (int *x){
   *x = 25;
}

int main (void){
    int apple = 10;
    printf("1回目:%d\n" , apple);

//参照渡し
    keisan(&apple);

    printf("書き換えました\n");
    printf("2回目:%d\n", apple);

} */

//複数の戻り値を返す
/* #include <stdio.h>

void keisan(int n1, int n2, int *tasu, int *hiku){
    *tasu = n1 + n2;
    *hiku = n1 - n2;
}

int main (void){
    int num1 = 30;
    int num2 = 10;
    int tasizan = 0;
    int hikizan = 0;
    keisan(num1, num2, &tasizan, &hikizan);
    printf("%d", tasizan);
    printf("%d", hikizan);
    return 0;
} */

//ポインタの構造体
/* #include<stdio.h>

struct Fruits{
    char name[128];
    int price;
    int zaiko;

};

int main (void){
    struct Fruits store = {"apple", 150, 50};
    struct Fruits *p;
    p = &store;
    printf("名前:%s\n", (*p).name);
    printf("名前:%s\n", p->name);
    return 0;
} */

//void *pandaの存在（隠ぺいや，汎用ポインタとして使用する）

//ポインタのポインタ（ダブルポインタ）
int  ** ppnum; //(ppは別につけなくてもいい)
//ポインタ関数の番地の設定を，別の関数へ依頼する場合にダブルポインタ変数が引数となる

/* ポインタ変数は変数名の前に「*」(アスタリスク)を付けて宣言します。ポインタ変数には変数のアドレスを代入します。

変数のアドレスは変数名の前に「&」(アンパサンド)を付けて表します。変数とポインタ変数は同じ型である必要があります。 */

// 配列の要素はメモリ上の番号つまりアドレスが連続していますので配列の要素を操作する場合に

/* しかし、常に1行あたりの要素数や行数が固定とは限りません。1行あたりの要素数や行数も変数を使って場合によっては配列のサイズを変更したいですよね。

変数を使って配列のサイズを変更し要素を割り当てることを動的に要素を割り当てるといいます。動的に要素を割り当てる際にはmalloc関数を使用します。

malloc関数の引数には配列全体で使用するバイト数を入力します。配列全体で使用するバイト数を入力したmalloc関数を配列のポインタに代入して使用します。

また2次元の配列になると1つの配列でメモリ領域を大きく使う場合もでてきます。使わなくなったメモリを放っておかないように、メモリの解放をこまめに行うことをおススメします。

メモリの解放にはfree関数を使用します。free関数を使用するには、ヘッダーファイル「stdlib.h」をインクルードする必要があります。 */


/* メモリの静的確保と動的確保
この記事の本題であるポインタを用いた1次元配列について説明していきたいのですが、その前にメモリの静的確保と動的確保について説明します。
　静的確保とは、配列を作成する際に、必要なメモリサイズがコンパイル時点で決まっている際のメモリの確保です。一方、動的確保とは、必要なメモリサイズが実行時にしか決まらない際のメモリの確保です。画像処理などのように、処理するデータによって必要な配列の大きさが異なる際には動的なメモリ確保が必要になります。
 */

#include <stdio.h>

int main(){
    /*静的確保①*/
    int A[] = {1,2,3,4,5};

    /*静的確保②*/
    const int n = 5;
    int B[n];
    for(int i=0; i<n; i++){
        B[i] = i;
    }

    return 0;
}


//二次元配列として扱う場合
#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
	int m, n;
	m = 5;
	n = 3;
 
	int **nums1;
	nums1 = malloc(sizeof(int *) * n); // ｎ行個分のアドレスを保持する領域を確保
 
	for(int i = 0; i < n; i++) {
		nums1[i] = malloc(sizeof(int) * m); // 1行分のデータを保持する領域を確保
	}
 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			nums1[i][j] = i * m + j; // 初期化
			if(j < m -1) {
				printf("%d,", nums1[i][j]);
			} else {
				printf("%d\n", nums1[i][j]);
			}
		}
	}
 
	// メモリ解放
	for(int i = 0; i < n; i++) {
		free(nums1[i]);
	}
	free(nums1);
 
	int **nums2, *arr;
	nums2 = malloc(sizeof(int *) * n); // ｎ行個分のアドレスを保持する領域を確保
	arr = malloc(sizeof(int) * m * n); // m×n個のデータを保持する一連の領域を確保
 
	for(int i = 0; i < n; i++) {
		nums2[i] = arr + i * m;
	}
 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			nums2[i][j] = i * m + j; // 初期化
			if(j < m -1) {
				printf("%d,", nums2[i][j]);
			} else {
				printf("%d\n", nums2[i][j]);
			}
		}
	}
 
	// メモリ解放
	free(arr);
	free(nums2);
 
	return 0;
}

#include <stdio.h>
#include <stdlib.h> //malloc関数,free関数を使用する際に必要

int main(){
    int n = 5;
    float* Array;    //行列の先頭をポインタとして定義
    Array = (float*)malloc(n * sizeof(float));  //ポインタArrayの先のメモリを動的に確保
    printf("Array = %p\n", Array);   //A配列の0番目の要素のアドレスが入る
    for(int i=0; i<n; i++){
        printf("Array[%d] = %f &Array[%d] = %p\n", i, Array[i], i, &Array[i]);
    }

    /*配列の要素に値を代入する*/
    printf("\n**奇数の配列を作成**\n");
    for(int i=0; i<n; i++){
        Array[i] = 2*i+1;
        printf("Array[%d] = %f\n", i, Array[i]);
    }
    printf("*Array = %f\n", *Array);    //ポインタArrayの先の要素はArray[0]と同じ

    free(Array);    //malloc関数で確保したメモリを解放
    return 0;
}

//mallocとは動的メモリを確保する関数（引数で指定するバイト数分のメモリが確保され，確保したメモリ領域へのポインタを返す）
//確保したメモリはfree関数で必ず開放する必要がある
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
    entity->str = (char*)mallco(sizeof(strct));

    //メモリに文字列を代入
    //sprintf関数は書式付き文字列を文字配列に格納する
    sprintf(entity->str, "%s %s!", "HELLO", "WORLD");
    printf("%s\n", entity->str);
    printf("%p\n", &entity->str);

    //メモリの解散
    free(entity->str);
    free(entity);

    return 0;
}