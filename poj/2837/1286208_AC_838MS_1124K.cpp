
#include <iostream>
using namespace std;

int main()
{
	int matrix[512][512];

	matrix[0][0]=1;
	matrix[0][1]=2;
	matrix[1][0]=3;
	matrix[1][1]=1;
	
	int i, j, k, n=4;
	for ( i=2 ; i<10 ; ++i ) {
		int t=n>>1, tt;
		for ( j=0 ; j<t ; ++j ) {
			for ( k=0 ; k<t ; ++k ) {
				tt=matrix[j][k];
				matrix[j][t+k]=tt+n;	// q2
				matrix[j+t][k+t]=tt;	// q4
				matrix[j+t][k]=tt+n;	// q3
			}
			matrix[t+j][j] -=1;
		}
		n <<= 1; // *=2
	}

	while ( cin >> n ) {
		n = 1<<n;
		for ( i=0 ; i<n ; ++i ) {
			for ( j=0 ; j<n ; ++j ) {
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}
}
