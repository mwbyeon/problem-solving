

#include <stdio.h>

void main()
{
	char keyboard[60]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

	char c;
	int i,j;

	for (i=0 ; (c=getchar()) != EOF  ; i++) {
		if ( c=='\n') putchar('\n');
		else if ( c==' ' ) putchar(' ');
		else {
			for (j=0 ; keyboard[j]!=c ; j++);
			putchar(keyboard[j-1]);
		}		
	}
}