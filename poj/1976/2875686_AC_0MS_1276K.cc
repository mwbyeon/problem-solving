#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define CLR(x,n) memset(x,n,sizeof(x))

int psg[50002], sum[50002], best[4][50002];

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n, m;
		scanf("%d", &n);
		REP(i, n) scanf("%d", &psg[i]);

		CLR(sum, 0);
		scanf("%d", &m);
		REP(i, m) sum[m-1] += psg[i];
		FOR(i, m, n) sum[i] = sum[i-1]-psg[i-m]+psg[i];
		//REP(i, n) printf("%d ", sum[i]); puts("");
		
		CLR(best, 0);
		
		best[0][1] = sum[1];
		best[1][m+1] = best[0][1]+sum[m+1];
		best[2][m+m+1] = best[1][m+1]+sum[m+m+1];

		//printf(" - %d %d %d \n", best[0][1], best[1][m+1], best[2][m+m+1]);

		REP(i, 3) FOR(j, m*i+2, n) {
			if ( i==0 ) best[0][j] = best[i][j-1] >? sum[j];
			else best[i][j] = best[i-1][j-m]+sum[j] >? best[i][j-1];
		}
		//REP(i, 3) { FOR(j, m*i+1, n) printf("%d ", best[i][j]); puts(""); }
		printf("%d\n", best[2][n-1]);
	}
	return 0;
}
