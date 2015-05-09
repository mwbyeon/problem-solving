
#include <iostream>
#include <cmath>
using namespace std;

#define MAX	50001
#define EPSILON 1e-15

typedef unsigned long ulong;

int main()
{
	double p, q, pp, qq, eq, prob;
	int red, black, total;
	double tmp[MAX];

	for ( int i=0 ; i<MAX ; ++i ) {
		tmp[i] = i;
		tmp[i] *= i;
		tmp[i] -= i;
	}

	while ( cin >> p >> q, p || q)
	{
		pp = p;
		qq = q;

		prob = p/q;
		for ( total=2 ; total<MAX ; ++total ) {
			pp = tmp[total];
			qq = prob*pp;
			black = (int)sqrt(qq);
			if ( fabs(tmp[black]/tmp[total]-prob) < EPSILON )
				break;
			black++;
			if ( fabs(tmp[black]/tmp[total]-prob) < EPSILON )
				break;
		}

		red = total-black;
		if ( total<MAX )
			cout << black <<' ' << red << endl;
		else 
			cout << "impossible" << endl;
	}
	return 0;
}	
