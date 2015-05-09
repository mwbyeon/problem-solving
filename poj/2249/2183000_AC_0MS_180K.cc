
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long n, k, res;
	int i, j;

	while ( cin >> n >> k, n || k ) {
		k = min(k, n-k);
		res = 1;
		for ( i=n, j=2 ; i>n-k ; --i ) {
			//cout << i << ' ' << j << endl;
			res *= i;	
			while ( j<=k && res%j==0 ) res /= j++;
		}
		cout << res << endl;
	}
	return 0;
}
