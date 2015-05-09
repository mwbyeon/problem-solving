#include <iostream>
using namespace std;

int fibo[150010];

int main()
{
	int n;

	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	int i;
	for ( i=3 ; ; ++i ) {
		if ( fibo[i-2]==0 && fibo[i-1]==1 ) break;
		fibo[i] = (fibo[i-1]+fibo[i-2])%10000;
	}

	while ( scanf("%d", &n), n>=0 ) {
		printf("%d\n", fibo[n%(i-2)]);
	}
	return 0;
}
