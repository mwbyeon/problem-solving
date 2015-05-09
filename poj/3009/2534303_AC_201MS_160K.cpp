#include <iostream>
#include <cstdio>
using namespace std;

int start_x, start_y, end_x, end_y;
int min_move;
int wid, hei;
bool board[21][21];
int dir[4][2] = { {0,-1}, {0, 1}, {-1, 0}, { 1, 0} };


inline bool valid(int x, int y) { return x>=0 && x<wid && y>=0 && y<hei; }

void curling(int now_x, int now_y, int cnt) {
	int k, i, j;

	if ( cnt==10 ) return;
	if ( !valid(now_x, now_y) ) return;
	
	cnt++;

	for ( k=0 ; k<4 ; ++k ) {
		i=now_y+dir[k][0], j=now_x+dir[k][1];
		if ( valid(j, i) && board[i][j] ) {
			for ( ; valid(j, i) && board[i][j] ; i+=dir[k][0], j+=dir[k][1] ) {
				if ( i==end_y && j==end_x ) {
					if ( min_move<0 || min_move > cnt ) min_move = cnt;
					return;
				}
			}
			if ( valid(j,i) ) {
				board[i][j] = true;
				curling(j-dir[k][1], i-dir[k][0], cnt);
				board[i][j] = false;
			}
		}
	}
}


int main()
{
	while ( scanf("%d %d", &wid, &hei), wid && hei ) {
		int t, i, j;
		
		min_move = -1;
		for ( i=0 ; i<hei ; ++i ) {
			for ( j=0 ; j<wid ; ++j ) {
				scanf("%d", &t);
				if ( t==1 ) board[i][j] = false;
				else {
					if ( t==2 ) start_x = j, start_y = i;
					if ( t==3 ) end_x = j, end_y = i;
					board[i][j] = true;
				}
			}
		}
		//printf("(%d,%d) -> (%d,%d)\n", start.x, start.y, end.x, end.y);
		curling(start_x, start_y, 0);
		printf("%d\n", min_move);
	}
	return 0;
}	
