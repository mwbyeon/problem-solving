#include <cstdio>
int main()
{
	int n, m, c;
	while ( scanf("%d %d %d", &n, &m, &c), n || m || c ) {
		int res = (n-7)*(m-7);
		printf("%d\n", res&1?res/2+c:res/2);
	}
	return 0;
}
