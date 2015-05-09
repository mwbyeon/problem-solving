#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
 
struct pt { double x,y; };
 
bool operator <(pt p, pt q) { return p.x<q.x-EPS || (p.x<q.x+EPS && p.y<q.y); }
bool operator ==(pt p, pt q) { return fabs(p.x-q.x)<EPS && fabs(p.y-q.y)<EPS; }
double skew(pt a, pt b, pt c) { return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); }
 
vector<pt> hull(vector<pt> p)
{
    if (p.size() <= 1) return p;
 
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
 
    int n = p.size(), k = 0;
    vector<pt> h;
 
    for (int i = 0; i < n; i++) {
        while (k >= 2 && skew(h[k-2], h[k-1], p[i]) < EPS)
            k--, h.pop_back();
        k++, h.push_back(p[i]);
    }
 
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && skew(h[k-2], h[k-1], p[i]) < EPS)
            k--, h.pop_back();
        k++, h.push_back(p[i]);
    }   
 
    return h;
}

double area(vector<pt> p) {
	double res = 0.0;
	p.push_back(p[0]);
	for ( int i=0 ; i<p.size() ; ++i )
		res += p[i].x*p[i+1].y-p[i+1].x*p[i].y;
	return res*0.5;
}

int main()
{
	int n;
	cin >> n;

	vector<pt> p(n);
	for ( int i=0 ; i<n ; ++i )
		cin >> p[i].x >> p[i].y;

	cout << floor( area(hull(p))/50.0 ) << endl;
	return 0;
}
