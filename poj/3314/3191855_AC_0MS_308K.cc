#include <iostream>

char board[100][10];
char block[100][10];
int pos[1000][2];

int main()
{
	int n, wid, hei, h;
	while ( scanf("%d %d %d", &n, &wid, &hei), n ) {
		memset(board, '.', sizeof(board));
		int top = 0, cnt;
		for ( int k=0 ; k<n ; ++k ) {
			scanf("%d", &h);
			cnt = 0;
			for ( int i=h-1 ; i>=0 ; --i ) {
				scanf("%s", block[i]);
				for ( int j=0 ; j<wid ; ++j ) if ( block[i][j]=='X' ) {
					pos[cnt][0] = top+i, pos[cnt][1] = j;
					++cnt;
				}
			}

			bool flag;
			while ( 1 ) {
				flag = true;
				for ( int i=0 ; i<cnt ; ++i ) {
					if ( pos[i][0]>0 && board[pos[i][0]-1][pos[i][1]]!='.' ) {
						flag = false;
						break;
					}
					else if ( pos[i][0]<=0 ) {
						flag = false;
						break;
					}
				}
				if ( flag ) {
					for ( int i=0 ; i<cnt ; ++i ) {
						--pos[i][0];
					}
				}
				else break;
			}

			bool possible = true;
			for ( int i=0 ; i<cnt ; ++i ) if ( pos[i][0] >= hei ) {
				possible = false;
				break;
			}

			if ( possible ) {
				for ( int i=0 ; i<cnt ; ++i ) {
					board[pos[i][0]][pos[i][1]] = 'X';
					top >?= pos[i][0]+1;
				}
			}
			else {
				int minv = 999;
				for ( int i=0 ; i<cnt ; ++i ) minv <?= pos[i][0];
				memset(board, '.', sizeof(board));
				printf("%d ", top);
				top = 0;
				for ( int i=0 ; i<cnt ; ++i ) {
					board[pos[i][0]-minv][pos[i][1]] = 'X';
					top >?= pos[i][0]-minv+1;
				}
			}
/*
			for ( int i=0 ; i<hei ; ++i ) {
				for ( int j=0 ; j<wid ; ++j ) printf("%c", board[i][j]);
				puts("");
			}
*/
		}
		printf("%d\n", top);
	}
	return 0;
}
