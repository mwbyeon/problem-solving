#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<string> VS;

VS board(8, string(8,' '));
int x, y;

void push(int i, int j, char dir) {
	char prev = board[i][j];
	board[i][j] = '.';
	if ( dir=='L' ) j--;
	if ( dir=='R' ) j++;
	if ( dir=='U' ) i--;
	if ( dir=='D' ) i++;

	if ( 0<=i && 0<=j && i<8 && j<8 ) {
		if ( board[i][j]!='.' ) push(i, j, dir);
		board[i][j] = prev;
	}
}

void move(int i, int j, char dir, int forward) {
	if ( forward==0 ) return;
	if ( dir=='L' ) j--;
	if ( dir=='R' ) j++;
	if ( dir=='U' ) i--;
	if ( dir=='D' ) i++;
	
	if ( 0<=i && 0<=j && i<8 && j<8 ) {
		if ( board[i][j]!='.' ) push(i, j, dir);
		x = j, y = i;
		move(i, j, dir, forward-1);
	}
}

int main()
{
	char dir;

	while ( cin >> board[0], board[0]!="--" ) {
		for ( int i=1 ; i<8 ; ++i ) {
			cin >> board[i];
			int p = board[i].find_first_of("><v^");
			if ( p!=string::npos ) {
				x = p, y = i;
				if ( board[i][p]=='<' ) dir = 'L';
				if ( board[i][p]=='>' ) dir = 'R';
				if ( board[i][p]=='^' ) dir = 'U';
				if ( board[i][p]=='v' ) dir = 'D';
				board[i][p] = '.';
		   }
		}

		string line;
		cin.ignore(1);
		while ( getline(cin, line), line!="#" ) {
			int forward = 0;
			if ( line=="turn right" ) {
				if ( dir=='L' ) dir = 'U';
				else if ( dir=='R' ) dir = 'D';
				else if ( dir=='U' ) dir = 'R';
				else if ( dir=='D' ) dir = 'L';
			}
			else if ( line=="turn left" ) {
				if ( dir=='L' ) dir = 'D';
				else if ( dir=='R' ) dir = 'U';
				else if ( dir=='U' ) dir = 'L';
				else if ( dir=='D' ) dir = 'R';
			}
			else if ( line=="turn back" ) {
				if ( dir=='L' ) dir = 'R';
				else if ( dir=='R' ) dir = 'L';
				else if ( dir=='U' ) dir = 'D';
				else if ( dir=='D' ) dir = 'U';
			}
			else {
				char tmp[8];
				sscanf(line.c_str(), "%s %d", tmp, &forward);
				move(y, x, dir, forward);
			}
			//printf("[%d,%d] %c %d\n", y, x, dir, forward);
		}
		if ( dir=='L' ) board[y][x] = '<';
		if ( dir=='R' ) board[y][x] = '>';
		if ( dir=='U' ) board[y][x] = '^';
		if ( dir=='D' ) board[y][x] = 'v';

		for ( int i=0 ; i<8 ; ++i ) cout << board[i] << endl;
		endl(cout);
	}
	return 0;
}
