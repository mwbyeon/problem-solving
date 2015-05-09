#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main()
{
	int T;
	int dice[10002][6], n;
	int oppo[] = { 5, 3, 4, 1, 2, 0 };
	int maxv[7][7];
	FOR(i, 1, 7) FOR(j, 1, 7) {
		for ( int k=6 ; k>0 ; --k ) if ( k!=i && k!=j ) {
			maxv[i][j] = k;
			break;
		}
		//printf("%d %d %d\n", i, j, maxv[i][j]);
	}

	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d", &n);
		REP(i, n) REP(j, 6) scanf("%d", &dice[i][j]);

		int res = 0;
		REP(k, 6) {
			int bottom = k, sum = 0;
			REP(i, n) {
				//printf("%d ", maxv[dice[i][bottom]][dice[i][oppo[bottom]]]);
				sum += maxv[dice[i][bottom]][dice[i][oppo[bottom]]];
				REP(j, 6) if ( dice[i][oppo[bottom]] == dice[i+1][j] ) {
					bottom = j;
					break;
				}
			}
			//printf(" = %d\n", sum);
			res >?= sum;
		}
		printf("%d\n", res);
	}
	return 0;
}
