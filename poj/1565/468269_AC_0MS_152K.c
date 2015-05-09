
#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
    char binary[32];

    int i, len, digit;
    long skew;

    gets(binary);

    while ( binary[0] != '0' )
    {
        len = (int)strlen(binary);
        skew = 0;

        for ( i=0 ; i<(int)strlen(binary) ; i++ )
        {
            digit = (int)pow(2,len)-1;
            if ( binary[i] != '0' )
                skew += (binary[i]-'0')*digit;
            len--;
        }
        printf("%d\n",skew);
        
        gets(binary);
    }

    return 0;
}