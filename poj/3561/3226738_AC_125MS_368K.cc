#include <iostream>
using namespace std;

int hei, wid;
char board[12][12];

inline bool valid(int i, int j) { return i>=0 && j>=0 && i<hei && j<wid; }

int dfs(int i, int j) {
	switch ( board[i][j] ) {
	case '-':
		if ( valid(i, j+1) && board[i][j+1]=='-' ) dfs(i, j+1);
		break;
	case '|':
		if ( valid(i+1, j) && board[i+1][j]=='|' ) dfs(i+1, j);
		break;
	case '/':
		if ( valid(i+1, j-1) && board[i+1][j-1]=='/' ) dfs(i+1, j-1);
		break;
	case '\\':
		if ( valid(i+1, j+1) && board[i+1][j+1]=='\\' ) dfs(i+1, j+1);
			break;
	}
	board[i][j] = '.';
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d %d", &hei, &wid);
		for ( int i=0 ; i<hei ; ++i ) scanf("%s", board[i]);
		
		int cnt = 0;
		for ( int i=0 ; i<hei ; ++i ) for ( int j=0 ; j<wid ; ++j ) if ( board[i][j]!='.' )
			cnt += dfs(i, j);
		
		puts(cnt==1?"CORRECT":"INCORRECT");
		
	}
	return 0;
}
