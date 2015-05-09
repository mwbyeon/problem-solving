#include <iostream>
using namespace std;

int main()
{
	int T, n;
	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d", &n);
		for ( int i=10 ; i<n ; i*=10 ) {
			if ( (n%i)/(i/10) > 4 )
				n += i-n%i;
			else 
				n -= n%i;
		}
		printf("%d\n", n);
	}
	return 0;
}
