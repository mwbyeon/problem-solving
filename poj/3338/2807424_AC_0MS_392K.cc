#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define CLR(x,n) memset(x,n,sizeof(x))

int hei, wid;
bool board[45][45];

void dfs(int x, int y) {
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	board[x][y] = false;
	REP(i, 4) {
		int xx = x+dx[i];
		int yy = y+dy[i];
		if ( xx>=0 && xx<hei && yy>=0 && yy<wid && board[xx][yy] )
			dfs(xx,yy);
	}
}

int main()
{
	while ( cin >> hei >> wid, hei && wid ) {
		int n, x1, y1, x2, y2;
		CLR(board, 1);
		hei = hei*2+1;
		wid = wid*2+1;
		cin >> n;
		while ( n-- ) {
			cin >> x1 >> y1 >> x2 >> y2;
			x1 *= 2; y1 *= 2; x2 *= 2; y2 *= 2;
			if ( x1 > x2 ) swap(x1, x2);
			if ( y1 > y2 ) swap(y1, y2);
			for ( int i=x1 ; i<=x2 ; ++i ) board[y1][i] = board[y2][i] = false;
			for ( int i=y1 ; i<=y2 ; ++i ) board[i][x1] = board[i][x2] = false;
		}

		int cnt = 0;
		REP(i, hei) REP(j, wid) {
			if ( board[i][j] ) {
				cnt++;
				dfs(i,j);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
