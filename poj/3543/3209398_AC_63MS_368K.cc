
#include <iostream>
using namespace std;

int main()
{
	int b, w;
	scanf("%d %d", &b, &w);
	if ( b > w ) swap(b,w);
	
	if ( b==0 && w==0 ) {
		puts("Impossible");
		return 0;
	}
	
	int n = 0, next = 0, add = 0;
	while ( next+(n%2) <= w && next <= b ) {
		if ( n%2==1 ) add += 2;
		next += add;
		++n;
	}
	printf("%d", n-1);

	return 0;
}
