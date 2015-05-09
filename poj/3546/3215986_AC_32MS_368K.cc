#include <iostream>
using namespace std;

bool res = true;
char board[10][10];

bool valid(int i, int j) { return i>=0 && j>=0 && i<10 && j<10; }

int dfs(int i, int j) {
	if ( !res ) return 0;
	if ( i==0 || j==0 || i==9 || j==9 ) { res = false; return 0; }

	if ( valid(i, j+1) && valid(i+1, j) && board[i][j+1]=='1' && board[i+1][j]=='1' ) { res = false; return 0; }
	if ( valid(i+1, j+1) && board[i+1][j+1]=='1' ) { res = false; return 0; }
	//if ( valid(i-1, j+1) && board[i-1][j+1]=='1' ) { res = false; return 0; }
	//if ( valid(i-1, j-1) && board[i-1][j-1]=='1' ) { res = false; return 0; }
	if ( valid(i+1, j-1) && board[i+1][j-1]=='1' ) { res = false; return 0; }
	
	board[i][j] = '0';	
	if ( valid(i, j+1) && board[i][j+1]=='1' ) return dfs(i, j+1)+1;
	if ( valid(i+1, j) && board[i+1][j]=='1' ) return dfs(i+1, j)+1;
	else return 1;
}

int main()
{
	for ( int i=0 ; i<10 ; ++i ) for ( int j=0 ; j<10 ; ++j ) scanf(" %c", &board[i][j]);
		
	int size[5] = {0, };
	for ( int i=0 ; i<10 ; ++i ) for ( int j=0 ; j<10 ; ++j ) if ( board[i][j]=='1' ) {
		size[dfs(i, j)]++;
	}
	
	for ( int i=1 ; i<5 ; ++i ) if ( size[i]!=5-i ) res = false;
	puts(res?"correct":"incorrect");
	
	return 0;
}

