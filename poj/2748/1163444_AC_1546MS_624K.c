
#include <stdio.h>

typedef unsigned long ulong;
typedef unsigned int  uint;

#define MAX 75002

int main()
{
	uint logs[MAX] = {1,2,5};

	ulong n, i;
	for ( i=3 ; i<MAX ; ++i ) {
		logs[i] = ((logs[i-1]<<1)+logs[i-1]-logs[i-2]+100000)%100000;
	}
	
	scanf("%ld", &n);
	do {
		scanf("%ld", &i);
		if ( i%75000 )
			printf("%ld\n", logs[i%75000-1]);
		else
			printf("%ld\n", logs[0]);
	} while ( --n );

	return 0;
}
