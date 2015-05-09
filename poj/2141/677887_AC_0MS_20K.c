
#include <stdio.h>
#include <ctype.h>

void main()
{
    char incode[27], c;

    scanf("%s ",incode);

    while ( (c=getchar())!='\n' ) {
        if ( c==' ' ) printf(" ");
        else if ( isupper(c) )
            printf("%c", toupper(incode[tolower(c)-'a']));
        else
            printf("%c", incode[c-'a']);
    }
}
