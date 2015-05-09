#include <iostream>
#include <set>
using namespace std;

struct Point {
	int x, y;
};

struct Slope {
	int dx, dy;
};

bool operator < ( const Slope& s1, const Slope& s2 ) {
	if ( s1.dx == s2.dx ) return s1.dy < s2.dy;
	return s1.dx < s2.dx;
}

int main()
{
	int n;
	Point pt[201];
	Slope slope[201*201];

	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i ) scanf("%d %d", &pt[i].x, &pt[i].y);

	int id = 0;
	set<Slope> res;
	for ( int i=0 ; i<n ; ++i ) {
		for ( int j=i+1 ; j<n ; ++j, ++id ) {
			int dx = pt[i].x - pt[j].x;
			int dy = pt[i].y - pt[j].y;
			if ( dy < 0 ) {
				dx *= -1;
				dy *= -1;
			}
			if ( dx == 0 ) dy = INT_MAX;
			else if ( dy == 0 ) dx = INT_MAX;
			else {
				int g = __gcd(dx, dy);
				dx /= g;
				dy /= g;
			}

			slope[i].dx = dx;
			slope[i].dy = dy;
			res.insert(slope[i]);
//			printf("%d %d\n", dx, dy);
		}
	}

	printf("%d\n", res.size());
	return 0;
}
