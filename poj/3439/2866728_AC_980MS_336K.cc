#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define CLR(x,n) memset(x,n,sizeof(x))

struct Point {
	Point(int _x=0, int _y=0) : x(_x), y(_y) { }
	int x, y;
};

Point pts[1024];
int best[1024];

double dist(Point& p1, Point& p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return dx*dx + dy*dy;
}

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n, beg, end;
		double len1, len2, len_sq;
		scanf("%d %d %d %lf %lf",&n, &beg, &end, &len1, &len2);
		beg--; end--;
		len_sq = (len1+len2)*(len1+len2);
		REP(i, n) scanf("%d %d", &pts[i].x, &pts[i].y);

		CLR(best, -1);
		queue<int> q;
		q.push(beg);
		best[beg] = 0;
		while ( !q.empty() ) {
			int curr = q.front(); q.pop();
			REP(i, n) {
				if ( best[i]==-1 && i!=curr && len_sq >= dist(pts[i], pts[curr]) ) {
					best[i] = best[curr] + 1;
					q.push(i);
				}
			}
		}
		if ( best[end]==-1 ) 
			puts("Impossible");
		else
			printf("%d\n", best[end]);
	}
	return 0;
}
