

#include <stdio.h>

int main()
{
    int num[16];
    int i,j;
    int doubles;

    scanf("%d",&num[0]);
    while ( num[0] != -1 )
    {
        for ( i=1 ; num[i-1] ; i++ )
            scanf("%d",&num[i]);
        for ( j=i ; j<15 ; j++ )
            num[j] = 0;

        doubles = 0;
        for ( i=0 ; num[i] ; i++ ) {
            for ( j=0 ; j<15 ; j++ )
            {
                if ( num[j]==num[i]*2 ) {
                    doubles++;
                    break;
                }
            }
        }
        printf("%d\n",doubles);

        scanf("%d",&num[0]);
    }
}