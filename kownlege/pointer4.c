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