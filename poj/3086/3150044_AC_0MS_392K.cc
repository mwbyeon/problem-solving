#include <iostream>
using namespace std;

int main()
{
	int table[301];
	table[0] = 0;
	for ( int i=1 ; i<=300 ; ++i ) {
		table[i] = table[i-1]+i*(i+2)*(i+1)/2;
	}
	
	int T, n;
	scanf("%d", &T);
	for ( int t=1 ; t<=T ; ++t ) {
		scanf("%d", &n);
		printf("%d %d %d\n", t, n, table[n]);
	}
	return 0;
}
