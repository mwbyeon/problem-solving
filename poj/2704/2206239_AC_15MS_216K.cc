#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 64

int main()
{
	int size;
	char board[MAX][MAX];
	long long dp[MAX][MAX];
	int i, j, step;

	while ( cin >> size, size>1 ) {
		for ( i=0 ; i<size ; ++i ) {
			cin >> board[i];
			for ( j=0 ; j<size ; ++j ) {
				board[i][j] -= '0';
				dp[i][j] = 0;
			}
		}
		
		dp[0][0] = 1;
		board[size-1][size-1] = 1;
		for ( i=0 ; i<size ; ++i ) {
			for ( j=0 ; j<size ; ++j ) {
				if ( dp[i][j] ) {
					step = board[i][j];
					if ( i+step<size && board[i+step][j] )
						dp[i+step][j] += dp[i][j];
					if ( j+step<size && board[i][j+step] )
						dp[i][j+step] += dp[i][j];
				}
			}
		}
/*
		for ( i=0 ; i<size ; ++i ) {
			for ( j=0 ; j<size ; ++j ) {
				cout << dp[i][j];
			}
			cout << endl;
		}
*/
		cout << dp[size-1][size-1] << endl;
	}
	return 0;
}
