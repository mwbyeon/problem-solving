#include <iostream>
using namespace std;

int wid, hei;
int board[100][100];
int memo[100][100];
int subsum[100][100]; // [0,0]~[i,j]

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		memset(board, 0, sizeof(board));
		memset(memo, 0, sizeof(memo));

		scanf("%d %d", &wid, &hei);
		for ( int i=0 ; i<hei ; ++i ) {
			for ( int j=0 ; j<wid ; ++j ) {
				scanf("%d", &board[i][j]);
				subsum[i][j] = board[i][j];
			}
		}

		for ( int i=0 ; i<hei ; ++i ) {
			for ( int j=0 ; j<wid ; ++j ) {
				if ( i>0 ) subsum[i][j] += subsum[i-1][j];
				if ( j>0 ) subsum[i][j] += subsum[i][j-1];
				if ( i>0 && j>0 ) subsum[i][j] -= subsum[i-1][j-1];
			}
		}

		for ( int i=0 ; i<hei ; ++i ) {
			for ( int j=0 ; j<wid ; ++j ) {
				memo[0][0] += (i+j)*board[i][j];
			}
		}

		int res = memo[0][0];
		for ( int i=0 ; i<hei ; ++i ) {
			if ( i!=0 ) memo[i][0] = memo[i-1][0] + subsum[i-1][wid-1] - (subsum[hei-1][wid-1]-subsum[i-1][wid-1]);
			for ( int j=1 ; j<wid ; ++j ) {
				memo[i][j] = memo[i][j-1] + subsum[hei-1][j-1] - (subsum[hei-1][wid-1]-subsum[hei-1][j-1]);
				res <?= memo[i][j];
			}
		}
		printf("%d blocks\n", res);
	}
	return 0;
}
