#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, abc;
	int n;
	int minv = INT_MAX;
	scanf("%d", &n);
	int sqrtn = sqrt(n);
	for ( int i=1 ; i<=sqrtn ; ++i ) {
		if ( n%i==0 ) {
			int nn = n/i;
			int sqrtnn = sqrt(nn);
			for ( int j=1 ; j<=sqrtnn ; ++j ) {
				if ( nn%j==0 ) {
					abc = i*j+j*nn/j+nn/j*i;
					if ( abc < minv ) {
						a = i;
						b = j;
						c = nn/j;
						minv = abc;
					}
				}
			}
		}
	}
	printf("%d %d %d\n", a, b,c);
	
	return 0;
}
