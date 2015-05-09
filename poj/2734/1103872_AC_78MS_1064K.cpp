
#define MAX 1000

#include <iostream>
using namespace std;

typedef struct Chess {
	int x, y;
} Chess;

bool isSubStr(char *str, char c) {
	for ( int i=0 ; i<sizeof(str) ; ++i )
		if ( str[i]==c ) return true;
	return false;
}

int main()
{
	int tCase = 0;
	char board[MAX+2][MAX+2];
	char *chess = "QKP";
	int rows, cols;
	int howQueens, howKnights, howPawns;
	int i, j, x, y;
	Chess *queens;
	Chess *knights;
	Chess *pawns;
	
	while ( cin >> rows >> cols, rows && cols )
	{
		// Initialize
		for ( i=0 ; i<rows ; ++i )
			for ( j=0 ; j<cols ; ++j )
				board[i+1][j+1] = 'O';

		// Input
		cin >> howQueens;
		queens = new Chess[howQueens];
		for ( i=0 ; i<howQueens ; ++i ) {
			cin >> queens[i].x >> queens[i].y;
			board[queens[i].x][queens[i].y] = 'Q';
		}
		cin >> howKnights;
		knights = new Chess[howKnights];
		for ( i=0 ; i<howKnights ; ++i ) {
			cin >> knights[i].x >> knights[i].y;
			board[knights[i].x][knights[i].y] = 'K';
		}
		cin >> howPawns;
		pawns = new Chess[howPawns];
		for ( i=0 ; i<howPawns ; ++i ) {
			cin >> pawns[i].x >> pawns[i].y;
			board[pawns[i].x][pawns[i].y] = 'P';
		}
		
		
		/** Processing Start **/

		// Queen;
		for ( i=0 ; i<howQueens ; ++i ) {
			x = queens[i].x;
			y = queens[i].y;

			// Left;
			for ( j=1 ; y-j>0 ; ++j ) {
				if ( isSubStr(chess, board[x][y-j]) )	break;
				else if ( board[x][y-j]=='O' ) board[x][y-j] = 'X';
			}
			// Right;
			for ( j=1 ; y+j<=cols ; ++j ) {
				if ( isSubStr(chess, board[x][y+j]) )	break;
				else if ( board[x][y+j]=='O' ) board[x][y+j] = 'X';
			}
			// Up;
			for ( j=1 ; x-j>0 ; ++j ) {
				if ( isSubStr(chess, board[x-j][y]) )	break;
				else if ( board[x-j][y]=='O' ) board[x-j][y] = 'X';
			}
			// Down;
			for ( j=1 ; x+j<=rows ; ++j ) {
				if ( isSubStr(chess, board[x+j][y]) )	break;
				else if ( board[x+j][y]=='O' ) board[x+j][y] = 'X';
			}
			// Quadrant 1;
			for ( j=1 ; x-j>0 && y+j<=cols ; ++j ) {
				if ( isSubStr(chess, board[x-j][y+j]) )	break;
				else if ( board[x-j][y+j]=='O' ) board[x-j][y+j] = 'X';
			}
			// Quadrant 2;
			for ( j=1 ; x-j>0 && y-j>0 ; ++j ) {
				if ( isSubStr(chess, board[x-j][y-j]) )	break;
				else if ( board[x-j][y-j]=='O' ) board[x-j][y-j] = 'X';
			}
			// Qudrant 3;
			for ( j=1 ; x+j<=rows && y-j>0 ; ++j ) {
				if ( isSubStr(chess, board[x+j][y-j]) )	break;
				else if ( board[x+j][y-j]=='O' ) board[x+j][y-j] = 'X';
			}
			// Qudrant 4;
			for ( j=1 ; x+j<=rows && y+j<=cols ; ++j ) {
				if ( isSubStr(chess, board[x+j][y+j]) )	break;
				else if ( board[x+j][y+j]=='O' ) board[x+j][y+j] = 'X';
			}
		}// End Queen;

		// Knight;
		for ( i=0 ; i<howKnights ; ++i ) {
			x = knights[i].x;
			y = knights[i].y;

			// 11 O'clock;
			if ( !isSubStr(chess, board[x-1][y]) || !isSubStr(chess, board[x-1][y-1]) )
				if ( !isSubStr(chess, board[x-2][y-1]) ) board[x-2][y-1] = 'X';
			// 1 O'clock;
			if ( !isSubStr(chess, board[x-1][y]) || !isSubStr(chess, board[x-1][y+1]) )
				if ( !isSubStr(chess, board[x-2][y+1]) ) board[x-2][y+1] = 'X';
			// 2 O'clock;
			if ( !isSubStr(chess, board[x][y+1]) || !isSubStr(chess, board[x-1][y+1]) )
				if ( !isSubStr(chess, board[x-1][y+2]) ) board[x-1][y+2] = 'X';
			// 4 O'clock;
			if ( !isSubStr(chess, board[x][y+1]) || !isSubStr(chess, board[x+1][y+1]) )
				if ( !isSubStr(chess, board[x+1][y+2]) ) board[x+1][y+2] = 'X';
			// 5 O'clock;
			if ( !isSubStr(chess, board[x+1][y]) || !isSubStr(chess, board[x+1][y+1]) )
				if ( !isSubStr(chess, board[x+2][y+1]) ) board[x+2][y+1] = 'X';
			// 7 O'clock;
			if ( !isSubStr(chess, board[x+1][y]) || !isSubStr(chess, board[x+1][y-1]) )
				if ( !isSubStr(chess, board[x+2][y+1]) ) board[x+2][y-1] = 'X';
			// 8 O'clock;
			if ( !isSubStr(chess, board[x-1][y]) || !isSubStr(chess, board[x-1][y-1]) )
				if ( !isSubStr(chess, board[x-2][y+1]) ) board[x+1][y-2] = 'X';
			// 10 O'clock;
			if ( !isSubStr(chess, board[x-1][y]) || !isSubStr(chess, board[x-1][y-1]) )
				if ( !isSubStr(chess, board[x-1][y-2]) ) board[x-1][y-2] = 'X';
		}// End Knight;
			
		// Result
		int result=0;
		for ( i=0 ; i<rows ; ++i )
			for ( j=0 ; j<cols ; ++j )
				if ( board[i+1][j+1]=='O' )
					++result;

		cout << "Board " << ++tCase << " has " << result << " safe squares." << endl;
		
		delete[] queens;
		delete[] knights;
		delete[] pawns;
		
	}
	return 0;

}
