/* average.c  縺薙�繝励Ο繧ｰ繝ｩ繝�縺ｮ蜷榊燕 */
#include<stdio.h>
#include"pgmlib.h"

/* 逕ｻ蜒蒐o.n1,n2,n3繧貞ｹｳ蝮�＠縺ｦNo.n4縺ｸ */
void average( int n1, int n2, int n3, int n4 );

int main(void)
{
    printf("笳丞次逕ｻ蜒擾ｼ代ｒ隱ｭ縺ｿ霎ｼ縺ｿ縺ｾ縺兔n");
    load_image( 0, "" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0 */
    printf("笳丞次逕ｻ蜒擾ｼ偵ｒ隱ｭ縺ｿ霎ｼ縺ｿ縺ｾ縺兔n");
    load_image( 1, "" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.1 */
    printf("笳丞次逕ｻ蜒擾ｼ薙ｒ隱ｭ縺ｿ霎ｼ縺ｿ縺ｾ縺兔n");
    load_image( 2, "" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.2 */
    printf("笳丞ｹｳ蝮�判蜒上ｒ菴懊ｊ縺ｾ縺兔n");
    average( 0, 1, 2, 3 ); /* 蟷ｳ蝮�喧 */
    save_image( 3, "" );   /* 逕ｻ蜒蒐o.3 竊� 繝輔ぃ繧､繝ｫ */
    return 0;
}

void average( int n1, int n2, int n3, int n4 )
/* 逕ｻ蜒蒐o.n1,n2,n3繧貞ｹｳ蝮�＠縺ｦNo.n4縺ｸ */
{
    int x,y;

    /* 逕ｻ蜒上し繧､繧ｺ */
    width[n4]=width[n1];
    height[n4]=height[n1];
    /* 蟷ｳ蝮�喧 */
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            image[n4][x][y] = ( image[n1][x][y] + image[n2][x][y] + image[n3][x][y] ) / 3;
        }
    }
}