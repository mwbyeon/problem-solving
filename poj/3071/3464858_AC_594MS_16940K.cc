#include <iostream>
using namespace std;

double table[128][128];
double memo[128][128][128];
int n;

double prob(int a, int b, int winner) {
	if ( memo[a][b][winner] > 1e-10 ) return memo[a][b][winner];
	if ( b-a==2 ) {
		if ( a==winner ) 
			return table[winner][b-1];
		else
			return table[winner][a];
	}

	double p = 0.0;
	int k = (a+b)/2;
	if ( winner < k ) {
		for ( int i=k ; i<b ; ++i ) p += prob(k, b, i)*table[winner][i];
		p *= prob(a, k, winner);
	}
	else {
		for ( int i=a ; i<k ; ++i ) p += prob(a, k, i)*table[winner][i];
		p *= prob(k, b, winner);
	}
	return memo[a][b][winner]=p;
}

int main()
{
	while ( scanf("%d", &n), n!=-1 ) {
		memset(memo, 0, sizeof(memo));
		n = 1<<n;
		for ( int i=0 ; i<n ; ++i ) for ( int j=0 ; j<n ; ++j ) scanf("%lf", &table[i][j]);
		double maxp = 1e-10;
		int res = -1;
		for ( int i=0 ; i<n ; ++i ) {
			double p = prob(0, n, i);
			//printf("%lf\n", p);
			if ( maxp < p ) {
				maxp = p;
				res = i;
			}
		}
		printf("%d\n", res+1);
	}
	return 0;
}
