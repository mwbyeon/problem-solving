#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)

int n, m, r, c;
char board[102][102];

int solve() {
	int res=0;
	REP(i, n) REP(j, m) {
		if ( i<=n-r && j<=m-c ) {
			if ( board[i][j]=='1' ) {
				res++;
				REP(k, r) REP(l, c) board[i+k][j+l] = (board[i+k][j+l]=='1'?'0':'1');
			}
		}
		else if ( board[i][j]=='1' ) return -1;
	}
	return res;
}

int main()
{
	while ( cin >> n >> m >> r >> c, n ) {
		REP(i, n) cin >> board[i];
		cout << solve() << endl;
	}
	return 0;
}
