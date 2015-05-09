#include <iostream>
using namespace std;

#define WALL 'o'
#define OUT  'O'

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char board[64][64];

inline bool valid(int x, int y) { return x>=0 && y>=0 && x<64 && y<64; }

void dfs(int x, int y) {
	board[y][x] = 'O';
	int xx, yy;
	
	for ( int i=0 ; i<4 ; ++i ) {
		xx = x+dx[i];
		yy = y+dy[i];
		if ( valid(xx,yy) && board[yy][xx]=='.' ) dfs(xx,yy);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int x, y;
	char dir;
	
	for ( int t=1 ; t<=T ; ++t ) {
		memset(board, '.', sizeof(board));
		scanf("%d %d", &x, &y);
		x *= 2;
		y *= 2;
		board[y][x] = 'W';
		
		while ( (dir=getchar())!='.' ) {
			switch ( dir ) {
			case 'N':
				board[++y][x] = 'W';
				board[++y][x] = 'W';
				break;
			case 'E':
				board[y][++x] = 'W';
				board[y][++x] = 'W';
				break;
			case 'W':
				board[y][--x] = 'W';
				board[y][--x] = 'W';
				break;
			case 'S':
				board[--y][x] = 'W';
				board[--y][x] = 'W';
				break;
			}
		}
		dfs(0,0);
		
		int x, y;
		for ( int i=0 ; i<64 ; ++i ) {
			for ( int j=0 ; j<64 ; ++j ) {
				if ( board[i][j]=='W' ) {
					for ( int k=0 ; k<4 ; ++k ) {
						x = j+dx[k];
						y = i+dy[k];
						if ( valid(x, y) && board[y][x]=='O' )  
							board[y][x] = 'X';
					}
				}
			}
		}

		printf("Bitmap #%d\n", t);
		for ( int i=63 ; i>0 ; i-=2 ) {
			for ( int j=1 ; j<64 ; j+=2 ) {
				printf("%c", board[i][j]=='O'?'.':board[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
