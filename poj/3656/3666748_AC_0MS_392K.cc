#include <iostream>
using namespace std;

int main()
{
	string line;
	while ( cin >> line, line!="END" ) {
		int n = line.length();
		int cnt=-1, len=-1, pos=-1, dist=999;
		int r1, r2;
		for ( int i=0 ; i<n ; ++i ) {
			for ( int j=1 ; j<n-i+1 ; ++j ) {
				int p = i, c = 0;
				while ( p < n && line[p]=='.' ) {
					++c;
					p += j;
				}
				if ( p >= n ) p -= j;

//				printf("[%d,%d], %d %d \n", i, j, c, p);

				if ( cnt < c ) {
					cnt = c;
					r1 = i, r2 = j;
				}
				else if ( cnt == c) {
					if ( len < p ) {
						len = p;
						r1 = i, r2 = j;
					}
					else if ( len == p ) {
						if ( pos < i ) {
							pos = i;
							r1 = i, r2 = j;
						}
						else if ( pos == i ) {
							if ( dist > j ) {
								dist = j;
								r1 = i, r2 = j;
							}
						}
					}
				}
			}
		}
		printf("%d %d\n", r1, r2);
	}
	return 0;
}
