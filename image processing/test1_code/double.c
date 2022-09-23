/* double.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"

/* No.0の大きさを面積4倍に変更してNo.1へ */
void double_image( int n1, int n2 );

int main(void)
{
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0     */
    double_image( 0, 1 );  /* No.0 繧呈僑螟ｧ縺励※ No.1 縺ｸ  */
    save_image( 1, "C:/Users/souta/github_code/picture/LENNA_sample_code6.pgm" );   /* 逕ｻ蜒蒐o.1 竊� 繝輔ぃ繧､繝ｫ     */
    return 0;
}

void double_image( int n1, int n2 )
/* 逕ｻ蜒� No.n1 繧抵ｼ泌阪＠縺ｦ逕ｻ蜒� No.n2 縺ｸ */
{
    int x,y,i,j;

    // No.1はNo.0の縦，横2倍
    width[n2]  = 2 * width[n1];
    height[n2] = 2 * height[n1];

    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            //ここで4×4マスに同じ階調値を代入している
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    image[n2][2*x+j][2*y+i] = image[n1][x][y];
                }
            }
        }
    }
}