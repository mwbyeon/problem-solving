
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long ulong;

int main()
{
	int t;
	ulong n, v, left, right;

	cin >> t;
	while ( t-- )
	{
		cin >> n;
		if ( n&1 ) left = right = n;
		else {
			v = 1;
			while ( n%(ulong)pow(2,v+1)!=(ulong)pow(2,v) ) v++;

			left = 1+n-pow(2,v);
			right = pow(2,v+1)-1 + n-pow(2,v);
		}

		cout << left <<' '<< right << endl;
	}
}