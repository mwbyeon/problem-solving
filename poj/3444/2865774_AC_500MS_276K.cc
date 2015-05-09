#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

int a[256], b[256];

int main()
{
	int n;
	while ( scanf("%d", &n), n ) {
		REP(i, n) scanf("%d", &a[i]);
		for ( int i=1 ; i<n ; i<<=1 ) {
			REP(j, i) {
				int c = j<<1;
				b[c] = (a[j]+a[j+i])/2;
				b[c+1] = a[j]-b[c];
			}
			REP(j, i) {
				int c = j<<1;
				a[c] = b[c];
				a[c+1] = b[c+1];
			}
		}
		REP(i, n-1) printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	}
	return 0;
}

