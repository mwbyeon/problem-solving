

#include <stdio.h>
#include <ctype.h>

void main()
{
char histo[72*4][26], c;
    
int cnt[26], max=0, i, j;    
for ( i=0 ; i<26 ; i++ ) {
histo[0][i] = 'A'+i;
cnt[i] = 1;
}

for ( i=0 ; i<4 ; i++ )
while ( (c=getchar())!='\n' )
if ( isupper(c) )
histo[cnt[c-'A']++][c-'A'] = '*';

for ( i=0 ; i<26 ; i++ )
if ( max < cnt[i] )
max = cnt[i];

for ( i=max-1 ; i>=0 ; i-- ) {
for ( j=0 ; j<26 ; j++ )
if ( histo[i][j] == '*' || isupper(histo[i][j]) )
printf("%C ",histo[i][j]);
else
printf("  ");
printf("\n");
}
}