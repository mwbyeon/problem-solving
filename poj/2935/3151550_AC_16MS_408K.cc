#include <iostream>
#include <queue>
using namespace std;

inline bool valid(int r, int c) { return r>=0 && c>=0 && r<13 && c<13; };

int main()
{
	const int dr[] = { -1, 1, 0, 0 };
	const int dc[] = { 0, 0, -1, 1 };
	const char dir[] = { 'N', 'S', 'W', 'E' };

	char board[16][16];
	int sr, sc, er, ec;
	int wr1, wc1, wr2, wc2;
	int trace[16][16];


	while ( scanf("%d %d", &sc, &sr), sc ) {
		memset(board, '.', sizeof(board));
		for ( int i=0 ; i<16 ; ++i ) {
			board[i][0] = board[0][i] = 'W';
			board[i][12] = board[12][i] = 'W';
		}

		scanf("%d %d", &ec, &er);
		sr = sr*2-1;
		sc = sc*2-1;
		er = er*2-1;
		ec = ec*2-1;
		board[sr][sc] = 'S';
		board[er][ec] = 'E';

		for ( int i=0 ; i<3 ; ++i ) {
			scanf("%d %d %d %d", &wc1, &wr1, &wc2, &wr2);
			if ( wc1 == wc2 ) {
				for ( int j=wr1 ; j<wr2 ; ++j ) board[j*2+1][wc1*2] = 'W';
			}
			else {
				for ( int j=wc1 ; j<wc2 ; ++j ) board[wr1*2][j*2+1] = 'W';
			}
		}

		bool visited[16][16];
		memset(visited, 0, sizeof(visited));
		memset(trace, -1, sizeof(trace));
		int t, r, c, rr, cc;

		queue<int> q;
		q.push( sr | (sc<<8) );
		visited[sr][sc] = 1;
		while ( !q.empty() ) {
			t = q.front(); q.pop();
			r = t & 0xFF;
			c = (t >>8) & 0xFF;
			if ( r==er && c==ec ) break;
			for ( int k=0 ; k<4 ; ++k ) {
				rr = r+2*dr[k];
				cc = c+2*dc[k];
				if ( valid(rr,cc) && !visited[rr][cc] && board[r+dr[k]][c+dc[k]]!='W' ) {
					q.push( rr | (cc<<8) );
					visited[rr][cc] = 1;
					trace[rr][cc] = k;
				}
			}
		}

		int res[64], cnt=0, k;
		while ( trace[r][c]!=-1 ) {
			res[cnt++] = trace[r][c];
			k = trace[r][c];
			r -= 2*dr[k];
			c -= 2*dc[k];
		}
		for ( int i=cnt-1 ; i>=0 ; --i ) printf("%c", dir[res[i]]);
		puts("");
	}
	return 0;
}
