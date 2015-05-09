#include <iostream>
using namespace std;

int get(long long y, long long x) {
	if ( x<2LL && y<2LL ) return x+y==2LL?-1:1;

	long long sz = 2;
	while ( x>=sz || y>=sz ) sz <<= 1;

	if ( x >= sz/2 && y >= sz/2 ) {
		return -get(y-sz/2, x-sz/2);
	}
	else {
		if ( x >= sz/2 ) x -= sz/2;
		if ( y >= sz/2 ) y -= sz/2;
		return get(y,x);
	}
}

int main()
{
	int T;

	long long n, x, y;
	int w, h;

	cin >> T;
	while ( T-- ) {
		cin >> n >> x >> y >> w >> h;
		for ( long long i=0 ; i<h ; ++i ) {
			for ( long long j=0 ; j<w ; ++j ) {
				printf("%d ", get(y+i, x+j));
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
