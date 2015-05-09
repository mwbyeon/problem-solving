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
		for ( int i=1 ; i<n ; i*=2 ) {
			REP(j, i) {
				b[2*j] = (a[j]+a[j+i])/2;
				b[2*j+1] = a[j]-b[2*j];
			}
			REP(j, i) {
				a[2*j] = b[2*j];
				a[2*j+1] = b[2*j+1];
			}
		}
		REP(i, n-1) printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	}
	return 0;
}