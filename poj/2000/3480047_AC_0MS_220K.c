#include <stdio.h>

void main()
{
	int n;
	int memo[10001] = {0,};
	
	int i, j, k = 1;
	for ( i=1 ; i<=10000 ; ++k)
		for ( j=0 ; j<k && i<=10000 ; ++j, ++i )
			memo[i] = memo[i-1]+k;

	while ( scanf("%d", &n), n )
		printf("%d %d\n", n, memo[n]);
}
