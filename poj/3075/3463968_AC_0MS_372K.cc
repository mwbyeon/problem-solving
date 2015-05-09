#include <iostream>
using namespace std;

char board[10];

bool valid()
{
	int fillo = 0, fillx = 0;
	int xcnt = 0, ocnt = 0;
	for ( int i=0 ; i<3 ; ++i ) {
		if ( board[i]!='.' && board[i]==board[i+3] && board[i+3]==board[i+6] ) {
			if ( board[i]=='O' ) fillo++; 
			if ( board[i]=='X' ) fillx++;
		}
		if ( board[i*3]!='.' && board[i*3]==board[i*3+1] && board[i*3+1]==board[i*3+2] ) {
			if ( board[i*3]=='O' ) fillo++; 
			if ( board[i*3]=='X' ) fillx++;
		}
		for ( int j=0 ; j<3 ; ++j ) {
			if ( board[i*3+j]=='X' ) xcnt++; 
			if ( board[i*3+j]=='O' ) ocnt++; 
		}
	}
	if ( board[0]!='.' && board[0]==board[4] && board[4]==board[8] ) {
		if ( board[0]=='O' ) fillo++; 
		if ( board[0]=='X' ) fillx++;
	}
	if ( board[2]!='.' && board[2]==board[4] && board[4]==board[6] ) {
		if ( board[2]=='O' ) fillo++; 
		if ( board[2]=='X' ) fillx++;
	}

	if ( fillo && fillx ) return false;
	if ( fillo==0 && fillx==0 ) return xcnt==5 && ocnt==4;

	if ( fillo==1 ) return xcnt == ocnt;
	if ( fillo>1 ) return false;
	
	if ( fillx==1 ) return xcnt-1==ocnt;
	if ( fillx==2 ) return xcnt==5 && ocnt==4;
	if ( fillx>2 ) return false;
	
	return xcnt==ocnt || xcnt-1==ocnt;
}

int main()
{
	while ( scanf("%s", board), board[0]!='e' )
		puts(valid()?"valid":"invalid");
	return 0;
}
