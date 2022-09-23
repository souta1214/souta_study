/* reverse.c   */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"

/* 画像の階調の反転 */
void reverse_image( int n );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );  /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0  */
    reverse_image( 0 );   /* No.0の画像の階調を反転させる（1→254）+()の中には画像番号  */
    save_image( 0, "C:/Users/souta/github_code/picture/LENNA_sample_code5.pgm" );  /* 逕ｻ蜒蒐o.0 竊� 繝輔ぃ繧､繝ｫ  */
    return 0;
}

/* void reverse_image(int n)
{
    int x,y;

    for(y = 0; height[n] ; y++)
    {
        for(x = 0; width[n] ; x++)
        {
            image[n][x][y] = 255 - image[n][x][y];
        }
    }
} */

void reverse_image( int n )
/* 逕ｻ蜒� No.n 縺ｮ髫手ｪｿ繧貞渚霆｢縺輔○繧� */
{
    int x,y;

    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            image[n][x][y] = 255 - image[n][x][y];
        }
    }
}