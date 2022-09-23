/* rotate.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h" /*階調画像用ライブラリーのインクルード*/

/* 画像No.1を反時計回りに90度回転させてNo.2へ */
void rotate_image( int n1, int n2 );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );  /*   */
    rotate_image( 0, 1 ); /* No.0を90度反時計回りに回転させてNo.1へ */
    save_image( 1, "C:/Users/souta/github_code/picture/LENNA_sample_code4.pgm" );  /* */
    return 0;
}

void rotate_image( int n1, int n2 )
/* 反時計回りに90度回転させて(No.1)からNo.2 */
{
    int x,y;

    width[n2]=height[n1];  height[n2]=width[n1];
    /* 反時計回りに90°回転 */
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            image[n2][y][height[n2]-x] = image[n1][x][y];
        }
    }
}