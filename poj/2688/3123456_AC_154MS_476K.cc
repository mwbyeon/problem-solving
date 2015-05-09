#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define INF 87654321

const int di[] = { -1, 1, 0, 0 };
const int dj[] = { 0, 0, -1, 1 };

int hei, wid;
char board[22][22];
int dirty[11][2], dc;
bool connect[20][20][20][20];
int shortest[11][11];
int memo[11][1025];

inline bool valid(int i, int j) { return i>=0 && j>=0 && i<hei && j<wid; }

int getDistance(int u, int v) {
	if ( u == v ) return 0;

	bool visited[hei][wid];
	memset(visited, 0, sizeof(visited));

	int pos = dirty[u][0]<<8 | dirty[u][1], t;
	visited[dirty[u][0]][dirty[u][1]] = 1;
	int i, j, c, ii, jj;
	queue<int> q;
	q.push(pos);
	while ( !q.empty() ) {
		t = q.front(); q.pop();
		i = (t>>8)&0xFF;
		j = t & 0xFF;
		c = (t>>16)&0xFFFF;
		for ( int k=0 ; k<4 ; ++k ) {
			ii = i+di[k];
			jj = j+dj[k];
			if ( valid(ii,jj) ) {
				if ( ii==dirty[v][0] && jj==dirty[v][1] ) return c+1;
				if ( connect[i][j][ii][jj] && !visited[ii][jj] ) {
					q.push(ii<<8 | jj | (c+1)<<16);
					visited[ii][jj] = 1;
				}
			}
		}
	}
	return INF;
}

// dynamic tsp
int go(int s, int v) { // s:start vertex, v:set of visited vertex
	if ( v==0 ) return 0;
	if ( memo[s][v]!=INF ) return memo[s][v];

	int minv = INF, buf;
	for ( int i=1 ; i<dc ; ++i ) {
		if ( (v&(1<<i))!=0 && s!=i ) {
			buf = go(i, v-(1<<i));
			if ( minv > shortest[s][i]+buf ) minv = shortest[s][i]+buf;
		}
	}
	memo[s][v] = minv;
	return minv;
}

int main()
{
	while ( scanf("%d %d", &wid, &hei), wid ) {
		dc = 1;
		memset(connect, 1, sizeof(connect));

		for ( int i=0 ; i<hei ; ++i ) {
			scanf("%s", board[i]);
			for ( int j=0 ; j<wid ; ++j ) {
				if ( board[i][j]=='x' ) {
					int ii, jj;
					for ( int k=0 ; k<4 ; ++k ) {
						ii = i+di[k];
						jj = j+dj[k];
						if ( valid(ii, jj) ) {
							connect[i][j][ii][jj] = connect[ii][jj][i][j] = 0;
						}
					}
				}
				else if ( board[i][j]=='*' ) {
					dirty[dc][0] = i;
					dirty[dc][1] = j;
					++dc;
				}
				else if ( board[i][j]=='o' ) {
					dirty[0][0] = i;
					dirty[0][1] = j;
				}
			}
		}

		for ( int i=0 ; i<dc ; ++i ) {
			for ( int j=i ; j<dc ; ++j ) {
				shortest[j][i] = shortest[i][j] = getDistance(i, j);
			}
		}
		for ( int i=0 ; i<dc ; ++i )
			for ( int j=0 ; j<(1<<dc) ; ++j )
				memo[i][j] = INF;

		int res = go(0, (1<<dc)-2);
		printf("%d\n", res==INF?-1:res);
	}
	return 0;
}
