#include <iostream>
using namespace std;

int room[50][50];
bool checked[50][50];
int hei, wid;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

inline bool valid(int i, int j) { return i>=0 && j>=0 && i<hei && j<wid; }

int go(int x, int y) {
	checked[x][y] = 1;
	int res = 1;
	
	int xx, yy;
	for ( int i=0 ; i<4 ; ++i ) {
		xx = x+dx[i];
		yy = y+dy[i];
		if ( (room[x][y]&(1<<i))==0 && !checked[xx][yy] ) {
			res += go(xx, yy);
		}
	}
	return res;
	
}

int main()
{
	scanf("%d %d", &hei, &wid);
	for ( int i=0 ; i<hei ; ++i ) {
		for ( int j=0 ; j<wid ; ++j ) {
			scanf("%d", &room[i][j]);
		}
	}
	
	int cnt = 0, size = 0;
	
	memset(checked, 0, sizeof(checked));
	for ( int i=0 ; i<hei ; ++i ) {
		for ( int j=0 ; j<wid ; ++j ) {
			if ( !checked[i][j] ) {
				++cnt;
				size >?= go(i, j);
			}
		}
	}
	printf("%d\n%d", cnt, size);
	
	return 0;
}