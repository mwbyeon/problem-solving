#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair

#define x first
#define y second

typedef pair<int,int> Point;

int main()
{
	int n;
	scanf("%d", &n);

	Point pts[n+1];
	REP(i, n) scanf("%d %d", &pts[i].x, &pts[i].y);
	sort(pts, pts+n);

	int res = 0;
	REP(i, n) FOR(j, i+1, n) {
		int dx = pts[j].x - pts[i].x;
		int dy = pts[j].y - pts[i].y;
		if ( binary_search(pts, pts+n, mp(pts[i].x-dy, pts[i].y+dx)) && binary_search(pts, pts+n, mp(pts[j].x-dy, pts[j].y+dx)) ) 
			++res;
	}
	printf("%d\n", res/2);
	return 0;
}
