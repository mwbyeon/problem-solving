
#include <stdio.h>
#include <memory.h>

#define MAX 1001

typedef __int64 llong;
int road[MAX][MAX], west[MAX];
int main()
{
	int T, t;
	int i, j;
	int n, m, k, e, w, re;
	llong total;

	scanf("%d", &T);
	for ( t=0 ; t<T ; ++t ) {
		scanf("%d %d %d", &n, &m, &k);

		memset(road, 0x00, sizeof(road));
		memset(west, 0x00, sizeof(west));
		while ( k-- ) {
			scanf("%d %d", &e, &w);
			road[e][w]++;
		}

		total = 0;
		for ( i=1 ; i<=n ; ++i ) {
			re = 0;
			for ( j=1 ; j<=m ; ++j ) {
				total += re*west[j];
				if ( road[i][j] ) {
					re += road[i][j];
					west[j] += road[i][j];
				}
			}
		}
		printf("Test case %d: %I64d\n", t+1, total);
	}
	return 0;
}

