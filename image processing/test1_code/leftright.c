/* leftright.c  */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"

/* 画像No.1を左右反転させて画像No.2へ */
void lr_reverse( int n1, int n2 );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );  /*  */
    lr_reverse( 0, 1 );   /* No.0を左右反転させて　No.1へ */
    save_image( 1, "C:/Users/souta/github_code/picture/LENNA_sample_code3.pgm" );  /*  */
    return 0;
}

void lr_reverse( int n1, int n2 )
/* 画像No.1を左右反転させて階調値を画像No.2へ代入 */
{
    int x,y;

    // 横幅，縦幅は同じにそろえる
    width[n2]=width[n1];  height[n2]=height[n1];
    /* 左右反転 */
    for(y=0;y<height[n1];y++)
    {
        for(x=0;x<width[n1];x++)
        {
            image[n2][x][y] = image[n1][width[n1]-1-x][y];
        }
    }
}