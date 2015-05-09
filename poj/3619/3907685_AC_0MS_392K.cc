#include <iostream>
using namespace std;

int main()
{
	int n, k, p;
	int s, t, r;
	
	scanf("%d %d", &n, &k);
	while ( k-- ) {
		scanf("%d %d %d", &s, &t, &r);
		p = n;
		int res = 0;
		while ( p > s*t ) {
			p -= s*t;
			res += t+r;
		}
		while ( p > 0 ) {
			p -= s;
			res ++;
		}
		printf("%d\n", res);
	}
	return 0;
}
