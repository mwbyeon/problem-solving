#include <iostream>
using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char board[101][101];
int hei, wid;

inline bool valid(int x, int y) { return x>=0 && y>=0 && x<hei && y<wid; }

void dfs(int x, int y)
{
	board[x][y] = '*';
	for ( int i=0 ; i<8 ; ++i ) {
		int xx = x+dx[i];
		int yy = y+dy[i];
		if ( valid(xx,yy) && board[xx][yy]=='@' ) 
			dfs(xx,yy);
	}
}

int main()
{
	while ( scanf("%d %d", &hei, &wid), hei ) {
		int res = 0;
		for ( int i=0 ; i<hei ; ++i ) scanf("%s", board[i]);
		for ( int i=0 ; i<hei ; ++i )
			for ( int j=0 ; j<wid ; ++j )
				if ( board[i][j]=='@' )
					dfs(i,j), ++res;
		printf("%d\n", res);
	}
	return 0;
}	
