#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define CLR(x,n) memset(x,n,sizeof(x))

bool checked[20][20][4];
int board[20][20];
int win, x, y;
int dx[] = { 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1 };

void solve() {
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
