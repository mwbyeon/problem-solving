
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 51

int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}

int main()
{
	int n;
	int seq[MAX];
	int relatively;
	int i, j;

	while ( scanf("%d", &n), n ) {
		for ( i=0 ; i<n ; ++i )
			scanf("%d", &seq[i]);
		
		relatively = 0;
		for ( i=0 ; i<n ; ++i )
			for ( j=i+1 ; j<n ; ++j )
				if ( gcd(seq[i],seq[j])==1 ) 
					relatively++;

		if ( relatively )
			printf("%.6f\n", sqrt(6.0*n*(n-1)/relatively/2) );
		else
			puts("No estimate for this data set.");
	}
	return 0;
}
	
