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
	Point(double _x=0.0, double _y=0.0) : x(_x), y(_y) {}
	double x, y;
	void print() { printf(" x=%.3lf y=%.3lf\n", x, y); }
};

double a[32], b[32], c[32], d[32];
Point pts[32][32];

inline double area(Point& p1, Point& p2, Point& p3, Point& p4) {
	return fabs(0.5*(p1.x*p2.y + p2.x*p3.y + p3.x*p4.y + p4.x*p1.y - p1.y*p2.x - p2.y*p3.x - p3.y*p4.x - p4.y*p1.x));
}

int main()
{
	int n;
	while ( scanf("%d ", &n), n ) {
		REP(i, n) scanf("%lf", &a[i+1]);
		REP(i, n) scanf("%lf", &b[i+1]);
		REP(i, n) scanf("%lf", &c[i+1]);
		REP(i, n) scanf("%lf", &d[i+1]);

		++n;
		pts[0][0] = Point(0.0, 0.0);
		pts[0][n] = Point(0.0, 1.0);
		pts[n][0] = Point(1.0, 0.0);
		pts[n][n] = Point(1.0, 1.0);
		FOR(i, 1, n) {
			pts[i][0] = Point(a[i], 0.0);
			pts[i][n] = Point(b[i], 1.0);
			pts[0][i] = Point(0.0, c[i]);
			pts[n][i] = Point(1.0, d[i]);
		}

		FOR(i, 1, n) {
			FOR(j, 1, n) {
				double m1, m2, b1, b2, x, y;
				if ( abs(b[i]-a[i]) < 1e-8 ) {
					m2 = (d[j]-c[j])/1.0;
					b2 = c[j];
					pts[i][j] = Point(a[i], m2*a[i]+b2);
				}
				else {
					m1 = 1.0/(b[i]-a[i]);
					m2 = (d[j]-c[j])/1.0;
					b1 = -m1*a[i];
					b2 = c[j];
					pts[i][j] = Point((b2-b1)/(m1-m2), m1*(b2-b1)/(m1-m2)+b1);
					//printf("* m1=%.3lf m2=%.3lf b1=%.3lf b2=%.3lf \n", m1, m2, b1, b2);
				}
				//printf(" (%d,%d) = %.3lf %.3lf\n", i, j, pts[i][j].x, pts[i][j].y);
			}
		}

		double res = 0.0;
		REP(i, n) REP(j, n) res >?= area(pts[i][j], pts[i][j+1], pts[i+1][j+1], pts[i+1][j]);
		printf("%.6lf\n", res);
	}
	return 0;
}
