#include <iostream>
#include <queue>
using namespace std;

inline bool valid(int n, int x, int y) { return x>=0 && y>=0 && x<n && y<n; }

int main()
{
	const int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
	const int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

	int T;
	scanf("%d", &T);

	bool visited[300][300];
	
	while ( T-- ) {
		int n, sx, sy, ex, ey;
		int t, x, y, c, xx, yy;
		scanf("%d %d %d %d %d", &n, &sx, &sy, &ex, &ey);
		memset(visited, 0, sizeof(visited));

		queue<int> q;
		q.push((sx<<9)+sy);
		visited[sx][sy] = 1;
		int res = -1;
		while ( !q.empty() ) {
			t = q.front(); q.pop();
			x = (t>>9)&0x1FF;
			y = t&0x1FF;
			c = (t>>18)+1;
			if ( x==ex && y==ey ) {
				res = c-1;
				break;
			}
			

			for ( int k=0 ; k<8 ; ++k ) {
				xx = x+dx[k];
				yy = y+dy[k];
				if ( valid(n, xx,yy) && !visited[xx][yy] ) {
					visited[xx][yy] = 1;
					q.push((c<<18)+(xx<<9)+yy);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

