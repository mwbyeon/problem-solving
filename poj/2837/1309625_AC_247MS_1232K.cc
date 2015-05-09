
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int matrix[512][512];

	matrix[0][0]=1;
	matrix[0][1]=2;
	matrix[1][0]=3;
	matrix[1][1]=1;
	
	int i, j, k, n=4, t, tt, t1, t2;
	for ( i=2 ; i<10 ; ++i ) {
		t=n>>1;
		for ( j=0 ; j<t ; ++j ) {
			for ( k=0 ; k<t ; ++k ) {
				t1 = j+t;
				t2 = k+t;
				tt=matrix[j][k];
				matrix[t1][t2]=tt;	// q4
				tt += n;
				matrix[j][t2]=tt;	// q2
				matrix[t1][k]=tt;	// q3
			}
			matrix[t+j][j] -=1;
		}
		n <<= 1; // *=2
	}

	while ( cin >> n ) {
		n = 1<<n;
		for ( i=0 ; i<n ; ++i ) {
			int *p = matrix[i], *end=p+n;
			while ( p!=end ) {
				printf("%d ", *p++);
			}
				
			
//			for ( j=0 ; j<n ; ++j ) {
//				printf("%d ", matrix[i][j]);
//			}
			puts("");
		}
	}
}
