#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define CLR(x,n) memset(x,n,sizeof(x))

int army[1024];
int main() {
	int R, n;
	while ( scanf("%d %d", &R, &n), R!=-1 ) {
		REP(i, n) scanf("%d", &army[i]);
		sort(army, army+n);
		n = unique(army, army+n)-army;

		int res = 0;

		for ( int i=0 ; i<n ; ++i ) {
			int start = army[i];
			while ( i<n && army[i+1]-start <= R ) {
				++i;
			}
			//printf("%d %d\n", start, army[i]);
			start = army[i];
			while ( i<n && army[i+1]-start <= R ) {
				++i;
			}
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
