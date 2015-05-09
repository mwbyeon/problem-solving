#include <stdio.h>
int main() {
	int n;
	while ( scanf("%d",&n)!=EOF ) puts(__builtin_popcount(n)==1?"YES":"NO");
	return 0;
}
