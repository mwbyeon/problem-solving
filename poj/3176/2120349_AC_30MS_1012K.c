
// dynamic programming
// similar problem : pku-1163 triangle

#include <stdio.h>
#include <memory.h>

#define MAX 352
#define max(x,y) (x)>(y)?(x):(y)

int main()
{
	int tri[MAX][MAX];
	int cost[MAX][MAX], max_cost;
	int n;
	int i, j;
	
	memset(tri, 0, sizeof(tri));
	memset(cost, 0, sizeof(cost));

	scanf("%d", &n);
	for ( i=1 ; i<=n ; ++i )
		for ( j=1 ; j<=i ; ++j )
			scanf("%d", &tri[i][j]);

	for ( i=1 ; i<=n ; ++i )
		for ( j=1 ; j<=i ; ++j )
			cost[i][j] = max(cost[i-1][j]+tri[i][j],cost[i-1][j-1]+tri[i][j]);

	max_cost = 0;
	for ( i=1 ; i<=n ; ++i )
		max_cost = max(max_cost,cost[n][i]);
	
	printf("%d\n", max_cost);
	return 0;
}
