
#include <iostream>
using namespace std;

#define MAX 100

int main()
{
	int i, j, size;
	int tri[MAX+2][MAX+2];
	int cost[MAX+2][MAX+2];

	
	cin >> size;
	
	memset(cost, 0, sizeof(cost));
	memset(tri, 0, sizeof(tri));
	
	for ( i=1 ; i<=size ; ++i )
		for ( j=1 ; j<=i ; ++j )
			cin >> tri[i][j];

	
	for ( i=1 ; i<=size ; ++i )
		for ( j=1 ; j<=i ; ++j )
			cost[i][j] = max(cost[i-1][j-1]+tri[i][j],cost[i-1][j]+tri[i][j]);

	int max=0;
	for ( j=1 ; j<=size ; ++j )
		if ( cost[size][j]>max )
			max = cost[size][j];

	cout << max << endl;

	return 0;
}
