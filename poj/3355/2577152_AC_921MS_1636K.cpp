#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
 
#define EPS 1e-8
 
typedef struct pt { double x,y; string s; };
 
bool operator <(pt p, pt q) { return p.x<q.x-EPS || (p.x<q.x+EPS && p.y<q.y); }
bool operator ==(pt p, pt q) { return fabs(p.x-q.x)<EPS && fabs(p.y-q.y)<EPS; }
double skew(pt a, pt b, pt c) { return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); }
 
void hull(vector<pt>& p)
{
	int i, n, t, k;
	vector<pt> h;
	
	sort(p.begin(), p.end());
    //p.erase(unique(p.begin(), p.end()), p.end());
 	n = p.size(), k = 0;
     for ( i = 0; i < n; i++) {
        while (k >= 2 && skew(h[k-2], h[k-1], p[i]) < EPS)
            k--, h.pop_back();
        k++, h.push_back(p[i]);
    }
 
    for ( i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && skew(h[k-2], h[k-1], p[i]) < EPS)
            k--, h.pop_back();
        k++, h.push_back(p[i]);
    }

//	cout << h.size() << endl;
	n = h.size();
	for ( i=0 ; i<n ; ++i )
		cout << h[i].s << " ";
	endl(cout);
}

int main()
{
	string line;
	double x, y;
	char c;
	while ( getline(cin, line) ) {
		istringstream sin(line);
		vector<pt> vp;
		pt p;
		while ( sin >> p.s ) {
			istringstream sin2(p.s);
			sin2 >> c >> p.x >> c >> p.y >> c;
			//cout << p.s << ' '<< p.x << ' ' << p.y << endl;
			vp.push_back(p);
		}
		hull(vp);
	}
	return 0;
}
