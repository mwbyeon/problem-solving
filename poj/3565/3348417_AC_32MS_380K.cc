#include <iostream>
using namespace std;

struct Point { 
	int x, y; 
};

int n;
Point ant[100], app[100];
int match[100];

inline bool ccw(Point& a, Point& b, Point& c) {
	int x1=b.x-a.x, y1=b.y-a.y;
	int x2=c.x-a.x, y2=c.y-a.y;
	return (x1*y2-y1*x2)>0;
}

inline bool intersect(Point& a, Point& b, Point& c, Point& d) {
	return (ccw(a,c,d)!=ccw(b,c,d)) && (ccw(a,b,c)!=ccw(a,b,d));
}

bool good() {
	for ( int i=0 ; i<n ; ++i )
		for ( int j=i+1 ; j<n ; ++j )
			if ( intersect(ant[i], app[match[i]], ant[j], app[match[j]]) ) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i ) scanf("%d %d", &ant[i].x, &ant[i].y);
	for ( int i=0 ; i<n ; ++i ) scanf("%d %d", &app[i].x, &app[i].y);
	for ( int i=0 ; i<n ; ++i ) match[i] = i;

	while ( !good() ) {
		for ( int i=0 ; i<n ; ++i ) {
			for ( int j=i+1 ; j<n ; ++j ) {
				if ( intersect(ant[i], app[match[i]], ant[j], app[match[j]]) ) {
					swap(match[i], match[j]);
				}
			}
		}
	}

	for ( int i=0 ; i<n ; ++i ) printf("%d\n", match[i]+1);
	return 0;
}
