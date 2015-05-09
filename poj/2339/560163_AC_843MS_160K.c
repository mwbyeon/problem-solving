#include <stdio.h>

char before[101][101], after[101][101];

void defeat(int a, int b, int c, int d)
{
    if ( before[a][b]=='R' && before[c][d]=='S' ) { after[c][d]='R';  return; }
    if ( before[a][b]=='R' && before[c][d]=='P' ) { after[a][b]='P';  return; }
    if ( before[a][b]=='S' && before[c][d]=='R' ) { after[a][b]='R';  return; }
    if ( before[a][b]=='S' && before[c][d]=='P' ) { after[c][d]='S';  return; }
    if ( before[a][b]=='P' && before[c][d]=='R' ) { after[c][d]='P';  return; }
    if ( before[a][b]=='P' && before[c][d]=='S' ) { after[a][b]='S';  return; }
}

int main()
{
    int t, row, col, day, i, j;

    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d %d %d", &row, &col, &day);

        for ( i=0 ; i<row ; i++ )
            for ( j=0 ; j<col ; j++ ) {
                scanf(" %c", &before[i][j]);
                after[i][j] = before[i][j];
            }


        while ( day-- )
        {
            for ( i=0 ; i<row ; i++ ) {
                for ( j=0 ; j<col ; j++ ) {
                    defeat(i,j,i,j+1);
                    defeat(i,j,i+1,j);
                }
            }

            for ( i=0 ; i<row ; i++ )
                for ( j=0 ; j<col ; j++ )
                    before[i][j] = after[i][j];
        }
        for ( i=0 ; i<row ; i++ ) {
            for ( j=0 ; j<col ; j++ )
                printf("%c",before[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
