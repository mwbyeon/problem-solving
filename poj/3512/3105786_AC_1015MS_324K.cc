
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int pts[1024][2];
float grad[1024];

int main()
{
	char line[32];

	int n=0, T=1;
	while ( gets(line) ) {
		if ( line[0]=='-' && line[1]=='-' ) {
			if ( n==0 ) return 0;

			int res = -1;
			for ( int i=0 ; i<n ; ++i ) {
				for ( int j=i+1 ; j<n ;++j ) {
					if ( pts[i][1] == pts[j][1] ) 
						grad[j] = 1e10;
					else
						grad[j] = (float)(pts[i][0]-pts[j][0])/(pts[i][1]-pts[j][1]);
				}
				sort(grad+i+1, grad+n);

				int cnt = 1;
				for ( int j=i+2 ; j<n ; ++j ) {
					if ( grad[j]-grad[j-1] < 1e-10 ) {
						++cnt;
					}
					else {
						if ( res < cnt ) res = cnt;
						cnt = 1;
					}
				}
				if ( res < cnt ) res = cnt;
			}

			printf("%d. %d\n", T++, res+1);
			n = 0;
		}
		else {
			sscanf(line, "%d %d", &pts[n][0], &pts[n][1]);
			++n;
		}
	}
	return 0;
}
