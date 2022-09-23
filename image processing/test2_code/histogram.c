/* histogram.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"
long int hist[256]; /* ヒストグラム用一次元配列 */
void make_histogram( int n );
void make_histogram_image( int h, int n );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );   /*  */
    make_histogram( 0 );    /* 画像o.0のヒストグラムの作成 */
    /* ヒストグラムの画像を作成して画像No.1に保存 */
    make_histogram_image( 256, 1 );
    save_image( 1, "C:/Users/souta/github_code/picture/LENNA_sample_code2-1.pgm" );   /*  */
    return 0;
}

void make_histogram( int n )
/* 画像No.nを元にヒストグラムを作る */
{
    int i,x,y;
    
    /* ヒストグラムの初期化*/
    for(i=0;i<256;i++) hist[i] = 0;
    /* 画像をラスタスキャンしてグラフを作る*/
    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            hist[ image[n][x][y] ]++; /* 累積を1増加 */
}

void make_histogram_image( int h, int n )
/* ヒストグラムを画像化（横256×縦h画素）して */
/* 画像No.nに記録 */
{
    int i,x,y;
    long int max; /* 最大頻度 */
    int takasa;   /* 各階調値の頻度の高さ*/
    
    /* 画像の縦，横の値入力 */
    width[n]=256;  height[n]=h;
    /* ヒストグラムの最大頻度maxを求める */
    max=0;
    for(i=0;i<256;i++)
        if ( hist[i] > max ) 
        {
            max = hist[i];
        }

    /* 縦幅をh画素に正規化しながら画像に値を代入+最頻値が画像の上端に接するように正規化する*/
    for(x=0;x<width[n];x++){
        takasa = (int)( h / (double)max * hist[x] );
        //double型にした弊害？
        if ( takasa > h ) 
        {
            takasa = h;

        }
        for(y=0;y<h;y++)
            if ( y < takasa ) 
            {
                image[n][x][h-1-y] = 0;
            }
            else image[n][x][h-1-y] = 255;
    }
}