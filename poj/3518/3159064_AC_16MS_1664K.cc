#include <iostream>
using namespace std;

#define MAX 1299710

bool isprime[MAX];

int main()
{
	isprime[2] = true;
	for ( int i=4 ; i<=MAX ; i+=2 ) {
		isprime[i] = false;
		isprime[i-1] = true;
	}
	int cnt = 1;
	for ( int i=3 ; i<MAX ; i+=2 ) {
		if ( isprime[i] ) {
			++cnt;
			for ( int j=i+i ; j<MAX ; j+=i ) isprime[j] = false;
		}
	}

	int n;
	while ( scanf("%d", &n), n ) {
		int res = 0;
		for ( int i=n ; !isprime[i] ; --i, ++res );
		for ( int i=n ; !isprime[i] ; ++i, ++res );
		printf("%d\n", res);
	}
	return 0;
}
