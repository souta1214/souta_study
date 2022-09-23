/* average2.c  縺薙�繝励Ο繧ｰ繝ｩ繝�縺ｮ蜷榊燕 */
#include<stdio.h>
#include"pgmlib.h"
#define NUM 3 /* 蟷ｳ蝮�ｒ縺ｨ繧狗判蜒上�邱乗焚 */

/* 逕ｻ蜒� No.n1 竊� 逕ｻ蜒� No.n2 */
void average2( int i, int n1, int n2 );

int main(void)
{
    int i;

    for(i=0;i<NUM;i++){
        printf("笳�%d逡ｪ逶ｮ縺ｮ逕ｻ蜒上ｒ隱ｭ縺ｿ霎ｼ縺ｿ縺ｾ縺兔n",i+1);
        load_image( 0, "" );      /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0 */
        average2( i, 0, 1 ); /* 逕ｻ蜒蒐o.0 竊� 逕ｻ蜒蒐o.1 */
    }
    save_image( 1, "" );          /* 逕ｻ蜒蒐o.1 竊� 繝輔ぃ繧､繝ｫ */
    return 0;
}

void average2( int i, int n1, int n2 )
/* 逕ｻ蜒� No.n1 竊� 逕ｻ蜒� No.n2 */
{
    int x,y;

    width[n2]=width[n1];
    height[n2]=height[n1];
    if ( i==0 ) init_image( n2, 0 );
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
           image[n2][x][y] += image[n1][x][y]/NUM;
        }
    }
}