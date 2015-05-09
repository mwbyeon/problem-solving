#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int L, M;
	while ( scanf("%d %d", &L, &M), L ) {
		L++;
		while ( M-- ) {
			int a, b;
			scanf("%d %d", &a, &b);
			L -= b-a+1;
		}
		printf("%d\n", L);
	}
	return 0;
}
