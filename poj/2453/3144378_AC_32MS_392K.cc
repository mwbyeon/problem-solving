#include <iostream>
using namespace std;

int main()
{
	int n;
	while ( scanf("%d", &n), n ) {
		int ones = __builtin_popcount(n);
		while ( __builtin_popcount(++n)!=ones );
		printf("%d\n", n);
	}
	return 0;
}
