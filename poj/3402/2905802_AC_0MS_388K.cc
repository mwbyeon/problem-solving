#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define CLR(x,n) memset(x,n,sizeof(x))

int row, col;
int chess[30][30];

bool valid(int r, int c) { return r>=0 && c>=0 && r<row && c<col; }

void set_queen() {
	string pos;
	cin >> pos;
	int r = pos[0]-'a';
	int c = atoi(pos.substr(1).c_str())-1;
	REP(i, row) REP(j, col) 
		if ( chess[i][j]==0 && (i==r || j==c || abs(i-r)==abs(j-c)) ) 
			chess[i][j] = 2; // attack
	chess[r][c] = 1; // queen
}

int main()
{
	int k;
	cin >> row >> col >> k;
	CLR(chess, 0);
	REP(i, k) set_queen();

	int maxv = 0;
	string pos="z99";
	
	REP(i, row) REP(j, col) if ( chess[i][j]!=1 ) {
		int cnt = 0;
		REP(a, row) REP(b, col) if ( chess[a][b]==0 && a!=i && b!=j && abs(i-a)!=abs(j-b) ) ++cnt;
		if ( cnt >= maxv ) {
			ostringstream sout;
			sout << char('a'+i) << j+1;
			//cout << sout.str() << ' ' << cnt << endl;
			if ( cnt > maxv ) pos = sout.str();
			else if ( cnt==maxv && pos > sout.str() ) pos = sout.str();
			maxv = cnt;
		}
	}
	cout << pos << '\n' << maxv << endl;
	return 0;
}
