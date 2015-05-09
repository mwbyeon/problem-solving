#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

int row, col;
char board[1024][1024];
int queen[128][2], knight[128][2];
const int km[8][2] = { {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2} };
const int qm[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,1}, {0,-1}, {1,-1}, {1,0}, {1,1} };

inline bool valid(int r, int c) {
	return r>0 && c>0 && r<=row && c<=col;
}

int main()
{
	for ( int T=1 ; scanf("%d %d", &row, &col), row ; ++T ) {
		int nq, nk, np;
		int r, c;
		memset(board, 0, sizeof(board));

		scanf("%d", &nq);
		for ( int i=0 ; i<nq ; ++i ) {
			scanf("%d %d", &queen[i][0], &queen[i][1]);
			board[queen[i][0]][queen[i][1]] = 'Q';
		}
		scanf("%d", &nk);
		for ( int i=0 ; i<nk ; ++i ) {
			scanf("%d %d", &knight[i][0], &knight[i][1]);
			board[knight[i][0]][knight[i][1]] = 'K';
		}
		scanf("%d", &np);
		for ( int i=0 ; i<np ; ++i ) {
			scanf("%d %d", &r, &c);
			board[r][c] = 'P';
		}

		int cnt = row*col-np-nq-nk;
		for ( int i=0 ; i<nq ; ++i ) {
			for ( int k=0 ; k<8 ; ++k ) {
				r = queen[i][0] + qm[k][0];
				c = queen[i][1] + qm[k][1];
				while ( valid(r,c) && board[r][c]<2 ) {
					if ( board[r][c]==0 ) {
						--cnt;
						board[r][c] = 1;
					}
					r += qm[k][0];
					c += qm[k][1];
				}
			}
		}

		for ( int i=0 ; i<nk ; ++i ) {
			for ( int k=0 ; k<8 ; ++k ) {
				r = knight[i][0]+km[k][0];
				c = knight[i][1]+km[k][1];
				if ( valid(r,c) && board[r][c]<2 ) {
					if ( board[r][c]==0 ) {
						--cnt;
						board[r][c] = 1;
					}
				}
			}
		}

		printf("Board %d has %d safe squares.\n", T, cnt);
	}
	return 0;
}
