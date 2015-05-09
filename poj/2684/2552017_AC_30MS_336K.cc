#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> POLY;
typedef vector<POLY> DATA;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define x first
#define y second

void move_to_origin(POLY& p) {
	int move_x = p[0].x;
	int move_y = p[0].y;
	REP(i, p.sz) {
		p[i].x -= move_x;
		p[i].y -= move_y;
	}
}

void rotate(POLY& p) {
	REP(i, p.sz) {
		swap(p[i].x, p[i].y);
		p[i].x = -p[i].x;
	}
}

bool same_polygon(POLY& cmp, POLY& p1, POLY& p2) {
	REP(i, 4) {
		rotate(p1);
		rotate(p2);
		if ( cmp==p1 || cmp==p2 ) return true;
	}
	return false;
}

int main()
{
	int n;
	while ( cin >> n, n ) {
		int p, x, y;
		DATA data(n, POLY());
		POLY cmp;

		cin >> p; // input template polygon
		REP(j, p) {
			cin >> x >> y;
			cmp.pb(mp(x,y));
		}

		REP(i, n) {
			cin >> p;
			REP(j, p) {
				cin >> x >> y;
				data[i].pb(mp(x,y));
			}
		}
		DATA rev_data(data);
		REP(i, n) reverse(ALL(data[i])); // reverse order polygon..

		move_to_origin(cmp);
		REP(i, n) {
			move_to_origin(data[i]);
			move_to_origin(rev_data[i]);
			if( same_polygon(cmp, data[i], rev_data[i]) )
				cout << i+1 << endl;
		}
		puts("+++++");
	}
	return 0;
}
