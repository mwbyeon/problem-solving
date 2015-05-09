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
#define x first
#define y second

typedef pair<int,int> Point;
typedef vector<pair<double,double> > Interval;

bool ccw(Point& p1, Point &p2, Point &p3) {
	return p1.x*p2.y-p1.y*p2.x+p1.y*p3.x-p1.x*p3.y+p2.x*p3.y>0;
}

double x_axis(Point& p1, Point& p2) {
	if ( p2.x == p1.x ) return p1.x;
	double m = 1.*(p2.y-p1.y)/(p2.x-p1.x);
	double b = p1.y-m*p1.x;
	return -b/m;
}

Interval combine(Interval shadow) {
	Interval res;
	int n = shadow.sz;
	REP(i, n) {
		bool fg = 0;
		REP(j, res.sz) {
			if ( shadow[i].first < res[j].second ) {
				if ( shadow[i].second > res[j].second )
					res[j].second = shadow[i].second;
				fg = 1;
			}
		}
		if ( !fg ) res.pb(shadow[i]);
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	while ( T-- ) {
		int n;
		Point source, a, b;
		Interval shadow;

		cin >> n >> source.x >> source.y;
		REP(i, n) {
			cin >> a.x >> a.y >> b.x >> b.y;
			double beg = x_axis(source, a);
			double end = x_axis(source, b);
			if ( end-beg < 1e-10 ) swap(beg, end);
			shadow.pb(mp(beg,end));
		}
		sort(ALL(shadow));
		cout << combine(shadow).sz+1 << endl;
	}
	return 0;
}
