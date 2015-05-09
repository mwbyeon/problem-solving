
#include <stdio.h>

typedef struct {
    int x;
    int	y;
} Point;

// main()안에 들어가면 Runtime Error.. >_<
Point cdn[200000];

void main()
{
    int tCase, i, stan, ollie;
    Point cet;

    // test case...
    scanf("%d",&tCase);

    while ( tCase )
    {
        stan = ollie = 0;

        // input
        for ( i=0 ; i<tCase ; i++ )
            scanf("%d %d", &cdn[i].x, &cdn[i].y);

        // 좌표축 설정;
        cet.x = cdn[(tCase-1)/2].x;
        cet.y = cdn[(tCase-1)/2].y;

        for ( i=0 ; i<tCase ; i++ ) {
            // 각각 사분면의 brownie 점들을 찾아서 포인트 증가... 단 좌표축에 포함된 brownie는 제외;
            if ( cdn[i].x>cet.x && cdn[i].y>cet.y )	stan++;		// 1사분면
            if ( cdn[i].x<cet.x && cdn[i].y<cet.y )	stan++;		// 3사분면
            if ( cdn[i].x<cet.x && cdn[i].y>cet.y )	ollie++;	// 2사분면
            if ( cdn[i].x>cet.x && cdn[i].y<cet.y )	ollie++;	// 4사분면
        }

        // output
        printf("%d %d\n",stan,ollie);

        scanf("%d",&tCase);
    }
}