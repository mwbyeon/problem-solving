#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

struct Point {
	int x, y;
};

Point stone[131073];

bool cmp1(Point p1, Point p2) {
	if ( p1.x==p2.x ) return p1.y<p2.y;
	return p1.x<p2.x;
}

bool cmp2(Point p1, Point p2) {
	if ( p1.y==p2.y ) return p1.x<p2.x;
	return p1.y<p2.y;
}
int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n, m, k;
		scanf("%d %d %d", &m, &n, &k);
		REP(i, k) scanf("%d %d", &stone[i].x, &stone[i].y);

		int res = 0;
		int row, col;

		sort(stone, stone+k, cmp1);
		row = 1, col = 0;

		REP(i, k) {
			while ( stone[i].x != row ) {
				if ( n-col > 1 ) ++res;
				++row;
				col = 0;
			}
			if ( stone[i].y-col>2 ) ++res;
			col = stone[i].y;
		}
		if ( n-col>1 ) ++res;
		res += n-row;

		sort(stone, stone+k, cmp2);
		row = 0, col = 1;
		REP(i, k) {
			while ( stone[i].y != col ) {
				if ( m-row > 1 ) ++res;
				++col;
				row = 0;
			}
			if ( stone[i].x-row>2 ) ++res;
			row = stone[i].x;
		}
		if ( m-row>1 ) ++res;
		res += m-col;

		printf("%d\n", res);
	}	
	return 0;
}
