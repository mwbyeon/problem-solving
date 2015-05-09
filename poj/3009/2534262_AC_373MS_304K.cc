#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,(n))
#define pb push_back
#define x first
#define y second

typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef pair<int,int> PII;

PII start, end;
int min_move;
int wid, hei;

int dir[4][2] = { {0,-1}, {0, 1}, {-1, 0}, { 1, 0} };

bool valid(int x, int y) { return x>=0 && x<wid && y>=0 && y<hei; }

void curling(VVB& board, int now_x, int now_y, int cnt) {
	if ( cnt==10 ) return;
	if ( !valid(now_x, now_y) ) return;

//	printf("(%d,%d) cnt=%d\n", now.x, now.y, cnt);
	
	cnt++;

	REP(k, 4) {
		int i=now_y+dir[k][0], j=now_x+dir[k][1];
		if ( valid(j, i) && board[i][j] ) {
			for ( ; valid(j, i) && board[i][j] ; i+=dir[k][0], j+=dir[k][1] ) {
				if ( i==end.y && j==end.x ) {
					if ( min_move<0 || min_move > cnt ) min_move = cnt;
					return;
				}
			}
			if ( valid(j,i) ) {
				board[i][j] = true;
				curling(board, j-dir[k][1], i-dir[k][0], cnt);
				board[i][j] = false;
			}
		}
	}
}


int main()
{
	while ( scanf("%d %d", &wid, &hei), wid && hei ) {
		VVB board(hei, VB(wid));
		min_move = -1;

		int t;
		REP(i, hei) REP(j, wid) {
			scanf("%d", &t);
			if ( t==1 ) board[i][j] = false;
			else {
				if ( t==2 ) start.x = j, start.y = i;
				if ( t==3 ) end.x = j, end.y = i;
				board[i][j] = true;
			}
		}
		//printf("(%d,%d) -> (%d,%d)\n", start.x, start.y, end.x, end.y);
		curling(board, start.x, start.y, 0);
		printf("%d\n", min_move);
	}
	return 0;
}	
