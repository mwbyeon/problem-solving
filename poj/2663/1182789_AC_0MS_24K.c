
#include <stdio.h>

int main()
{
	int solution[31]={1,0,3}, i, n;
	for ( i=3 ; i<=30 ; ++i ) {
		if ( i & 1 )
			solution[i] = 0;
		else {
			solution[i] = 4;
			solution[i] *= solution[i-2];
			solution[i] -= solution[i-4];
		}
	}
	while ( 1 ) {
		scanf("%d", &n);
		if ( n==-1 ) return 0;
		printf("%d\n", solution[n]);
	}
	return 0;
}
	
			
			
