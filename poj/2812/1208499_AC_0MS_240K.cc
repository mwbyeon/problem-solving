
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct point {
	float x, y;
} point;

double area(point&, point&, point&);

int main()
{
	int n;
	while ( cin >> n , n )
	{
		point p;
		vector<point> poly;
		poly.reserve(n+1);

		for ( int i=0 ; i<n ; ++i ) {
			cin >> p.x >> p.y;
			poly.push_back(p);
		}
		poly.push_back(*poly.begin());

		double area=0, v;
		
		for ( int i=n ; i>0 ; --i )
			area += poly[i].x*poly[i-1].y-poly[i-1].x*poly[i].y;
		area *= 0.5;

		cin >> v;
		printf("BAR LENGTH: %.2f\n", v/area);
	}
	return 0;
}
		
			
