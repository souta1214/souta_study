/* trans0.c */
#include<stdio.h>
#include"C:\Users\souta\github_code\my_include\pgmlib.h"

//fが変換前の原画像の階調値，g=trans_table[f]が返還後の画像の階調値
int trans_table[256];  /* 変換表（グラフ）*/
void trans( int n );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0 */
    trans( 0 );            /* 画像No.0の濃度変換 */
    save_image( 0, "C:/Users/souta/github_code/picture/LENNA_sample_code2-2.pgm" );   /* 逕ｻ蜒蒐o.0 竊� 繝輔ぃ繧､繝ｫ */
    return 0;
}

void trans( int n )
/* 画像No.nの画像を変換グラフで変換する */
{
    int f;
    int x,y;
    
    /* 変換表の設定 */
    for(f=0;f<256;f++){
        trans_table[f] = 255 - f;   /* y=x (変換無し */
    }
    /* 各画素の階調を変換表に従って変換 */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            image[n][x][y] = trans_table[ image[n][x][y] ];
        }
    }
}