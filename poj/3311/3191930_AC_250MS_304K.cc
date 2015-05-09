#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int dist[11][11];
	int order[12];

	while ( scanf("%d", &n), n ) {
		for ( int i=0 ; i<=n ; ++i ) for ( int j=0 ; j<=n ; ++j ) scanf("%d", &dist[i][j]);
		for ( int k=0 ; k<=n ; ++k ) for ( int i=0 ; i<=n ; ++i ) for ( int j=0 ; j<=n ; ++j )
			dist[i][j] <?= dist[i][k]+dist[k][j];
		for ( int i=0 ; i<=n ; ++i ) order[i] = i;

		int res = INT_MAX;
		do {
			int sum = dist[order[n]][0];
			for ( int i=1 ; i<=n ; ++i ) sum += dist[order[i-1]][order[i]];
			res <?= sum;
		} while ( next_permutation(&order[1], &order[n+1]) );

		printf("%d\n", res);
	}
	return 0;
}
