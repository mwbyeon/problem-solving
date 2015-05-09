
// dynamic programming
// similar problem : pku-1163 triangle

#include <stdio.h>
#include <memory.h>

#define MAX 352
#define max(x,y) (x)>(y)?(x):(y)

int main()
{
	short cost[MAX][MAX], max_cost;
	int n;
	int i, j;
	
	memset(cost, 0, sizeof(cost));

	scanf("%d", &n);
	for ( i=1 ; i<=n ; ++i )
		for ( j=1 ; j<=i ; ++j )
			scanf("%d", &cost[i][j]);

	for ( i=1 ; i<=n ; ++i )
		for ( j=1 ; j<=i ; ++j )
			cost[i][j] = max(cost[i-1][j]+cost[i][j],cost[i-1][j-1]+cost[i][j]);

	max_cost = 0;
	for ( i=1 ; i<=n ; ++i )
		if ( max_cost < cost[n][i] )
			max_cost = cost[n][i];
	
	printf("%d\n", max_cost);
	return 0;
}
