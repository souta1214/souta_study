/* #include <stdio.h>

int main(void)
{
    printf("HELLO\n");
    int index = 1;
    char array[] = "ABCDE";
    char ans = index[array];
    printf("%d\n", ans);
    printf("%d\n", index);
 */
    //プログラムが正常に終了したことをシェルに伝える
    //ジョブ管理システムでは非常に大切
    /* そんな何十本ものプログラムが集まったジョブネットですが、実行中にあるプログラムがエラーを起こしてしまった場合、そのプログラム以降に動く予定のプログラムが正常な動作をしてくれない場合があります。
    大規模なシステムでこの問題が発生してしまうと、誤ったデータが登録されるなど、場合によっては大損害になりかねません。
    そうした場合に、ジョブ管理システムでは各プログラムの動きを監視して、正常に終了していなければその時点でジョブネットそのものを停止させることができます。
    この監視に用いられるのが、各プログラムの終了コード、つまりreturn文でOSへと返された値を元に判定しているのです。
    返された値が0であれば正常終了だから次のプログラム、255であれば異常終了だからジョブネットを停止させる等、返された値を元に処理を振り分けることができます。 */
  /*   return 0;
} */

/* 配列とポインタには
array[index] == *(array + index)の関係がある
配列名はその配列の先頭アドレスを示す
つまり、右辺の（）内の計算は単なる計算ではなく、アドレス演算になります。
アドレス演算における基本単位はそのアドレスが指す型に依存します。 */

//多次元配列の三原則
/* 多次元配列としての型情報は持っているが、配列の要素を持つ配列、の要素を持つ配列...として多次元配列は成立している。
実際の要素の値としては、1つ次元を落とした型を保持している。
これらの多次元配列を例外を除いた、式中のオペランドとして用いた場合、暗黙の型変換によって１次元失った型へのポインタとなる。 */

/* int array[3][4];
これは，要素数4のint型配列の要素数3のint型配列（つまり配列を要素に持った配列） */
#include<stdio.h>

int main(void){
    int array[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};
    printf("%d\n", *(*(array+1)+2));

    
}

#include <stdio.h>
int main(void){
    int array[3][4] = {{1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12}};
    printf("%d\n", *(*(array+1)+2));
    printf("%d\n", array[1][2]);
    printf("%d\n", 1[array][2]);
    printf("%d\n", 2[1[array]]);
    printf("%d\n", 2[array[1]]);
    return 0;
}