#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)

int n, wid, hei, s, t;
bool map[102][102];
int trees[502][2];

int main()
{
	while ( scanf("%d", &n), n ) {
		memset(map, 0, sizeof(map));
		scanf("%d %d", &wid, &hei);
		REP(i,n) {
			scanf("%d %d", &trees[i][0], &trees[i][1]);
			map[--trees[i][1]][--trees[i][0]] = true;
		}
		scanf("%d %d", &s, &t);

		int res = 0;
		REP(i,hei-t+1) REP(j,wid-s+1) {
//			if ( map[i][j] ) {
				int cnt = 0;
				REP(k,n) if ( j<=trees[k][0] && trees[k][0]<j+s && i<=trees[k][1] && trees[k][1]<i+t ) cnt++;
				res >?= cnt;
//			}
		}
		printf("%d\n", res);
	}
	return 0;
}
