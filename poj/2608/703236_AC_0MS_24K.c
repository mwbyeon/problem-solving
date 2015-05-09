
#include <stdio.h>
#include <string.h>

int main()
{
    char word[21], pre, code[] = "AEOIOUHWYBFPVCGJKQSXZDTLMNR";
    int len, i, j;

    while ( scanf("%s",word)!=EOF )
    {
        len = strlen(word);
        for ( i=0 ; i<len ; i++ ) {
            for ( j=0 ; code[j]!=word[i] ; j++ );
            if ( 0<=j && j<=8 )     word[i] = '0';
            if ( 9<=j && j<=12 )    word[i] = '1';
            if ( 13<=j && j<=20 )   word[i] = '2';
            if ( 21<=j && j<=22 )   word[i] = '3';
            if ( 23==j )            word[i] = '4';
            if ( 24<=j && j<=25 )   word[i] = '5';
            if ( 26==j )            word[i] = '6';
        }
        if ( word[0]!='0' ) printf("%c",word[0]);
        for ( i=1 ; i<len ; i++ ) {
            if ( word[i]!=word[i-1] && word[i]!='0' )
                printf("%c",word[i]);
        }
        printf("\n");
    }
}
