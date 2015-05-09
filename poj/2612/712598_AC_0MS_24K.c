#include <stdio.h>

int main()
{
    char mine[12][12], click[12][12], result[12][12];

    int row, i, j, cnt, mine_click=0;
    scanf("%d ",&row);

    for ( i=1 ; i<=row ; i++ )
        for ( j=1 ; j<=row ; j++ )
            scanf("%c ",&mine[i][j]);


    for ( i=1 ; i<=row ; i++ )
        for ( j=1 ; j<=row ; j++ )
            scanf("%c ",&click[i][j]);

    for ( i=1 ; i<=row ; i++ )
        for ( j=1 ; j<=row ; j++ ) {
            if ( click[i][j] == 'x' ) {     // onclick
                if ( mine[i][j] == '*' )        mine_click = 1;

                cnt = 0;
                if ( mine[i-1][j-1] == '*' )    cnt++;
                if ( mine[i-1][j] == '*' )      cnt++;
                if ( mine[i-1][j+1] == '*' )    cnt++;
                if ( mine[i][j-1] == '*' )      cnt++;
                if ( mine[i][j+1] == '*' )      cnt++;
                if ( mine[i+1][j-1] == '*' )    cnt++;
                if ( mine[i+1][j] == '*' )      cnt++;
                if ( mine[i+1][j+1] == '*' )    cnt++;
                result[i][j] = cnt+'0';
            }
            else
                result[i][j] = '.';
        }

    if ( mine_click == 1 )
        for ( i=1 ; i<=row ; i++ )
            for ( j=1 ; j<=row ; j++ )
                if ( mine[i][j] == '*' )
                    result[i][j] = '*';

    for ( i=1 ; i<=row ; i++ ) {
        for ( j=1 ; j<=row ; j++ )
            printf("%c",result[i][j]);
        printf("\n");
    }

}
