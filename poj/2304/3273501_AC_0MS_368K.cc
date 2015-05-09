#include <iostream>
using namespace std;

int main()
{
	int p, a, b, c;
	while ( scanf("%d %d %d %d", &p, &a, &b, &c), p || a || b || c ) {
		int res = 1080;
		
		res += ((p+40)-a)%40*9;
		p = a;
		res += ((b+40)-p)%40*9;
		p = b;
		res += ((p+40)-c)%40*9;		
		
		printf("%d\n", res);
	}
	
	return 0;
}
