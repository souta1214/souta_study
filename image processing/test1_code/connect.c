/* connect.c */
#include<stdio.h>
#include"C:/Users/souta/github_code/my_include/pgmlib.h"

/* No.1とNo.2を結合してNo.3へ */
void connect_image( int n1, int n2, int n3 );

int main(void)
{
    printf("結合する一枚目の画像を選んでくださいn");
    load_image( 0, "C:/Users/souta/github_code/picture/LENNA.pgm" );       /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0  */
    printf("結合する二枚目の画像を選んでくださいn");
    load_image( 1, "C:/Users/souta/github_code/picture/LENNA.pgm" );       /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.1  */
    printf("選ばれた画像を結合して出力しますn");
    connect_image( 0, 1, 2 );   /* 邨仙粋逕ｻ蜒上ｒ逕ｻ蜒蒐o.2縺ｸ */
    save_image( 2, "C:/Users/souta/github_code/picture/LENNA_sample_code7.pgm" );       /* 逕ｻ蜒蒐o.2 竊� 繝輔ぃ繧､繝ｫ  */
    return 0;
}

void connect_image( int n1, int n2, int n3 )
/* No.1とNo.2を結合してNo.3へ */
{
    int x,y;

    if (height[n1] != height[n2]){
        printf("これらの画像は結合できませんn");
        exit(1);
    } else if (width[n1] + width[n2] > MAX_IMAGESIZE){
        printf("これらの画像の結合は最大幅%dを超えていますn",
          MAX_IMAGESIZE);
        exit(1);
    } else {
        width[n3]  = width[n1] + width[n2];
        height[n3] = height[n1];
        for(y=0;y<height[n3];y++){
            for(x=0;x<width[n3];x++){
                if (x < width[n1])
                    image[n3][x][y] = image[n1][x][y];
                else
                    image[n3][x][y] = image[n2][x-width[1]][y];
            }
        }
    }
}