
#include <stdio.h>

#define MAX 1000000

int main()
{
    char digits[2][MAX+2], result[MAX+2];
    int len, i;

    scanf("%d",&len);
    for ( i=len-1 ; i>=0 ; i-- )
        scanf(" %c %c", &digits[0][i], &digits[1][i]);

    result[0] = 0;
    for ( i=0 ; i<len ; i++ ) {
        result[i] += digits[0][i]-'0'+digits[1][i]-'0';

        if ( result[i] > 9 ) {
            result[i] -= 10;
            result[i+1] = 1;
        } else
            result[i+1] = 0;
    }
    if ( result[len]>0 )
        len++;

    for ( i=len-1 ; i>=0 ; i-- )
        printf("%d",result[i]);
    printf("\n");
}
