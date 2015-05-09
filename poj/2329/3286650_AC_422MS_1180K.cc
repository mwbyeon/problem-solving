#include <iostream>
using namespace std;

int matrix[200][200];
int zeros[40000][2], zc = 0;
int table[200][200][2];
bool amb[200][200];

int main()
{
	int n;

	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i ) for ( int j=0 ; j<n ; ++j ) {
		scanf("%d", &matrix[i][j]);
		if ( matrix[i][j]==0 ) {
			zeros[zc][0] = i;
			zeros[zc][1] = j;
			zc++;
		}
		table[i][j][0] = INT_MAX;
		table[i][j][1] = 0;
		amb[i][j] = false;
	}

	for ( int i=0 ; i<n ; ++i ) {
		for ( int j=0 ; j<n ; ++j ) {
			if ( matrix[i][j]!=0 ) {
				for ( int k=0 ; k<zc ; ++k ) {
					int ii = zeros[k][0];
					int jj = zeros[k][1];
					int dist = abs(i-ii)+abs(j-jj);
					if ( dist < table[ii][jj][0] ) {
						table[ii][jj][0] = dist;
						table[ii][jj][1] = matrix[i][j];
						amb[ii][jj] = false;
					}
					else if ( dist == table[ii][jj][0] ) {
						amb[ii][jj] = true;
					}
				}
			}
		}
	}

	for ( int i=0 ; i<n ; ++i ) {
		for ( int j=0 ; j<n ; ++j ) {
			if ( matrix[i][j]==0 ) {
				matrix[i][j] = amb[i][j]?0:table[i][j][1];
			}
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}

	return 0;
}
