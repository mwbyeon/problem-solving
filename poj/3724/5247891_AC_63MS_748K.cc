#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double x[22], y[22];
int param[11];

bool solve(int idx)
{
	if ( idx == 11 ) 
	{
		bool res = true;
		double yy;
		for ( int i=0 ; i<n ; ++i )
		{
			double eps = exp(2.0*x[i]) - exp(x[i]);
			yy = 0.0;
			for ( int j=1 ; j<=10 ; ++j )
			{
				yy += exp(param[j]*x[i]);
			}

			if ( fabs(yy-y[i]) > eps )
			{
				res = false;
				break;
			}
		}

		return res;
	}

	for ( int i=param[idx-1] ; i<=10 ; ++i )
	{
		param[idx] = i;
		if ( solve(idx+1) ) return true;
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i )
	{
		scanf("%lf %lf", &x[i], &y[i]);
	}

	param[0] = 1;
	solve(1);
	
	for ( int i=1 ; i<=10 ; ++i )
	{
		printf("%d\n", param[i]);
	}
	return 0;
}


