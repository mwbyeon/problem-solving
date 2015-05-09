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

bool checked[20][20][4];
int board[20][20];
int win, x, y;

void solve() {
	int dx[] = { 1, 1, 0, -1 };
	int dy[] = { 0, 1, 1, 1 };

	REP(i, 19) REP(j, 19) {
		REP(k, 4) if ( !checked[i][j][k] ) {
			checked[i][j][k] = 1;
			int cnt = 1;
			int ii = i, jj = j;
			checked[ii][jj][k] = 1;
			while ( ii<19 && jj<19 && board[ii][jj] && board[ii][jj]==board[ii+dx[k]][jj+dy[k]] ) {
				ii += dx[k];
				jj += dy[k];
				checked[ii][jj][k] = 1;
				++cnt;
			}
			if ( cnt==5 ) {
				win = board[i][j];
				x = i+1;
				y = j+1;
				return;
			}
		}
	}
	win = 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		REP(i, 19) REP(j, 19) scanf("%d", &board[i][j]);
		CLR(checked, 0);
		solve();
		if ( win ) 
			printf("%d\n%d %d\n", win, x, y);
		else
			puts("0");
	}
	return 0;
}
