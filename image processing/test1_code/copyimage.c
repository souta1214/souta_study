/* copyimage.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h" /*階調画像用ライブラリーのインクルード*/

int main(void)
{
    load_image(0,"C:/Users/souta/github_code/picture/LENNA.pgm"); /*画像No.1にファイルから画像を読み込む*/
    save_image(0,"C:/Users/souta/github_code/picture/LENNA_sample_code1.pgm"); /* 画像No,1の画像をファイルに出力する */
    return 0;
}