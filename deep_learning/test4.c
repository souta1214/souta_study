#include <stdio.h>

// int ary[]は一見すると配列に見えるが実体はただのポインタ．
void func(int ary[]){
//void func(int *ary)でもいい
    //int型のポインタのサイズを返す
    printf("func: sizeof ary = %ld\n", sizeof ary);
    /* 
    printf("%d\n", ary[0]);
    printf("%d\n", ary[1]);
    printf("%d\n", ary[2]);
 */
}
int main (void)
{
    int ary[] = {1, 2, 3};

    printf("main: sizeof ary = %ld\n", sizeof ary);

    func(ary);

    return 0;
}