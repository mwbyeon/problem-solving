#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> PII;
typedef stack<PII> STACK;
typedef vector<string> VS;

int wid, hei;
int dir[][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

inline bool valid(int i, int j) { 
	return ( i>=0 && j>=0 && i<hei && j<wid );
}

int main()
{


	while ( cin >> wid >> hei, wid && hei ) {
		VS board(hei, string(wid,'.'));
		VS check(hei, string(wid,'x'));
		STACK s;

		for ( int i=0 ; i<hei ; ++i ) {
			cin >> board[i];
			for ( int j=0 ; j<board[i].size() ; ++j )
				if ( board[i][j]=='@' ) {
					s.push(make_pair(i,j));
					check[i][j] = 'o';
				}
		}

		while ( !s.empty() ) {
			PII p(s.top());
			s.pop();
			for ( int i=0 ; i<4 ; ++i ) {
				int x = p.first+dir[i][0];
				int y = p.second+dir[i][1];
				if ( valid(x,y) && board[x][y]!='#' && check[x][y]=='x' ) {
				   s.push(make_pair(x,y));
				   check[x][y] = 'o';
				}
			}
		}
		int cnt = 0;
		for ( int i=0 ; i<hei ; ++i )
			cnt += count(check[i].begin(), check[i].end(), 'o');
		cout << cnt << endl;
	}
	return 0;
}
