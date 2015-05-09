// http://www.brand.site.co.il/riddles/200809a.html
#include <iostream>
using namespace std;

void go(int n)
{
	if ( n == 1 ) return ;
	int k = n/2;
	for ( int i=1 ; i<=k ; ++i ) printf("%d %d %d\n", i+k, 2, i-1);
	printf("%d %d %d\n", 1, k, k);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int res = n/2+1;
	if ( n < 3 ) res = n-1;
	printf("%d\n", res);

	if ( n%2 == 0 ) {
		go(n-1);
		printf("%d 1 0\n", n);
	}
	else {
		go(n);
	}

	return 0;
}

