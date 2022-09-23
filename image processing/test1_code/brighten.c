/* brighten.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"

// 画像No.n をshiftだけ明るくする(プロトタイプ宣言)
void brighten( int n, int shift);

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm");  /* ファイル→画像No.0 */
    brighten( 0, 100);  /* 画像No.0の明るさを100上げる */
    save_image( 0, "C:/Users/souta/github_code/picture/LENNA_sample_code2.pgm");  /* 画像No.0→ファイル */
    return 0;

}

void brighten( int n, int shift)
// 画像No.n をshiftだけ明るくする
{
    int x,y,brightness;
    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++){
            brightness = image[n][x][y] + shift;
            if (brightness > 255 ) brightness = 255;
            image[n][x][y] = brightness;
        }
}