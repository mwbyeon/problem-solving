#include <stdio.h>

int main()
{
char key[]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./", c;
int j;
while( (c=getchar()) != EOF ) {
if ( c=='\n') printf("\n");
else if ( c==' ' ) printf(" ");
else {
for (j=0 ; key[j]!=c ; j++);
putchar(key[j-1]);
}		
}
}

