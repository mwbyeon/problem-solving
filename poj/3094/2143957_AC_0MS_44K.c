
#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int sum, i;
	
	while ( (c=getchar())!='#' ) {
		sum = 0;
		i=1;
		if ( c!='\n' ) 
			do {
				if ( isupper(c) )
					sum += i*(c-'A'+1);
				i++;
			} while ( (c=getchar())!='\n');
		printf("%d\n", sum);
	}
	return 0;
}
			
