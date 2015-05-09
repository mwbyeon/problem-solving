#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

inline int sq(int n) { return n*n; }

int main()
{
	int rgb[16][3];
	for ( int i=0 ; i<16 ; ++i ) scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	int r, g, b, rr, gg, bb, minv;
	while ( scanf("%d %d %d", &r, &g, &b), r!=-1 ) {
		minv = INT_MAX;
		for ( int i=0 ; i<16 ; ++i ) {
			int t = sq(rgb[i][0]-r)+sq(rgb[i][1]-g)+sq(rgb[i][2]-b);
			if ( t < minv ) {
				minv = t;
				rr = rgb[i][0];
				gg = rgb[i][1];
				bb = rgb[i][2];
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, rr, gg, bb);
	}
	return 0;
}
