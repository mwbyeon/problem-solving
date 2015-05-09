#include <stdio.h>

typedef unsigned long ulong;
typedef unsigned int  uint;

#define MAX 75002

int main()
{
	uint logs[MAX] = {1,1,2,5};

	ulong n, i;
	for ( i=4 ; i<MAX ; ++i )
		logs[i] = (3*logs[i-1]-logs[i-2]+100000)%100000;
	
	scanf("%ld", &n);
	do {
		scanf("%ld", &i);
		printf("%ld\n", logs[i%75000]);
	} while ( --n );

	return 0;
}
