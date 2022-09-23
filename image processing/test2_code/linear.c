/* linear.c */
#include<stdio.h>
#include"pgmlib.h"

long int hist[256]; /* 繝偵せ繝医げ繝ｩ繝�逕ｨ�第ｬ｡蜈��蛻� */

void make_histgram( int n );
/* 逕ｻ蜒蒐o.n 繧貞�縺ｫ繝偵せ繝医げ繝ｩ繝�繧剃ｽ懊ｋ */
void make_histgram_image( int h, int n );
/* 繝偵せ繝医げ繝ｩ繝�繧堤判蜒丞喧(讓ｪ256ﾃ礼ｸｦh逕ｻ邏�)縺励※ */
/* 逕ｻ蜒蒐o.n縺ｫ險倬鹸縺吶ｋ */
void linear_transformation( int n );
/* hist[256]繧貞�縺ｫ縺励※逕ｻ蜒蒐o.n繧堤ｷ壼ｽ｢螟画鋤縺吶ｋ */

int main(void)
{
    load_image( 0, "" );   /* 繝輔ぃ繧､繝ｫ 竊� 逕ｻ蜒蒐o.0 */
    make_histgram( 0 );    /* 逕ｻ蜒蒐o.0縺ｮ繝偵せ繝医げ繝ｩ繝�縺ｮ菴懈� */
    /* 繝偵せ繝医げ繝ｩ繝�縺ｮ逕ｻ蜒上ｒ菴懊▲縺ｦ逕ｻ蜒蒐o.1縺ｫ菫晏ｭ� */
    make_histgram_image( 256, 1 );
    printf("***** 蜴溽判蜒上�繝偵せ繝医げ繝ｩ繝�縺ｮ逕ｻ蜒上ｒ菫晏ｭ倥＠縺ｾ縺呻ｼ蚕n");
    save_image( 1, "" );   /* 逕ｻ蜒蒐o.1 竊� 繝輔ぃ繧､繝ｫ */
    
    linear_transformation( 0 );  /* 逕ｻ蜒蒐o.0繧堤ｷ壼ｽ｢螟画鋤 */
    
    printf("***** 邱壼ｽ｢螟画鋤蠕後�逕ｻ蜒上ｒ菫晏ｭ倥＠縺ｾ縺呻ｼ蚕n");
    save_image( 0, "" );   /* 逕ｻ蜒蒐o.0 竊� 繝輔ぃ繧､繝ｫ */
    make_histgram( 0 );    /* 逕ｻ蜒蒐o.0縺ｮ繝偵せ繝医げ繝ｩ繝�縺ｮ菴懈� */
    /* 繝偵せ繝医げ繝ｩ繝�縺ｮ逕ｻ蜒上ｒ菴懊▲縺ｦ逕ｻ蜒蒐o.1縺ｫ菫晏ｭ� */
    make_histgram_image( 256, 1 );
    printf("***** 邱壼ｽ｢螟画鋤蠕後�逕ｻ蜒上�繝偵せ繝医げ繝ｩ繝�縺ｮ逕ｻ蜒上ｒ菫晏ｭ倥＠縺ｾ縺呻ｼ蚕n");
    save_image( 1, "" );   /* 逕ｻ蜒蒐o.1 竊� 繝輔ぃ繧､繝ｫ */
    return 0;
}

void linear_transformation( int n )
/* hist[256]繧貞�縺ｫ縺励※逕ｻ蜒蒐o.n繧堤ｷ壼ｽ｢螟画鋤縺吶ｋ */
{
    int fmin=-1,fmax=256;
    int x,y,g;

    /* 譛蟆上�譛螟ｧ髫手ｪｿ蛟､縺ｮ謗｢邏｢ */
    do fmin++; while(hist[fmin]==0);
    do fmax--; while(hist[fmax]==0);
    // printf("fmax = %d, fmin = %d\n",fmax,fmin);
    /* 逕ｻ蜒蒐o.n繧堤ｷ壼ｽ｢螟画鋤 */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            g = (int)( (double)(image[n][x][y] - fmin ) / 
                ( fmax - fmin ) * 255.0 );
            if ( g>255 ) g=255;
            else if ( g<0 ) g=0;
            image[n][x][y] = g;
        }
    }
}

void make_histgram( int n )
/* 逕ｻ蜒蒐o.n 繧貞�縺ｫ繝偵せ繝医げ繝ｩ繝�繧剃ｽ懊ｋ */
{
    long int hist2[256]; /* 菴懈･ｭ逕ｨ */
    int i,x,y;
    
    /* 繝偵せ繝医げ繝ｩ繝�縺ｮ蛻晄悄蛹� */
    for(i=0;i<256;i++)
        hist[i] = 0;
    /* 逕ｻ蜒上ｒ繝ｩ繧ｹ繧ｿ繧ｹ繧ｭ繝｣繝ｳ縺励※繧ｰ繝ｩ繝輔ｒ菴懊ｋ */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            hist[ image[n][x][y] ]++; /* 邏ｯ遨阪ｒ�大｢怜刈 */
        }
    }
}

void make_histgram_image( int h, int n )
/* 繝偵せ繝医げ繝ｩ繝�繧堤判蜒丞喧(讓ｪ256ﾃ礼ｸｦh逕ｻ邏�)縺励※ */
/* 逕ｻ蜒蒐o.n縺ｫ險倬鹸縺吶ｋ */
{
    int i,x,y;
    long int max; /* 譛螟ｧ鬆ｻ蠎ｦ */
    int takasa;   /* 蜷�嚴隱ｿ蛟､縺ｮ鬆ｻ蠎ｦ縺ｮ鬮倥＆ */
    
    /* 逕ｻ蜒上�邵ｦ繝ｻ讓ｪ縺ｮ蛟､縺ｮ蜈･蜉� */
    width[n]=256;  height[n]=h;
    /* 繝偵せ繝医げ繝ｩ繝�縺ｮ譛螟ｧ鬆ｻ蠎ｦmax繧呈ｱゅａ繧� */
    max=0;
    for(i=0;i<256;i++){
        if ( hist[i] > max )
            max = hist[i];
    }
    /* 邵ｦ蟷�ｒh逕ｻ邏�縺ｫ豁｣隕丞喧縺励↑縺後ｉ逕ｻ蜒上↓蛟､繧剃ｻ｣蜈･ */
    for(x=0;x<width[n];x++){
        takasa = (int)( h / (double)max * hist[x] );
        if ( takasa > h )
            takasa = h;
        for(y=0;y<h;y++){
            if ( y < takasa )
                image[n][x][h-1-y] = 0;
            else
                image[n][x][h-1-y] = 255;
        }
    }
}