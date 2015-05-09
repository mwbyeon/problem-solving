
#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while ( t-- )
	{
		int h, m;
		scanf("%d:%d", &h, &m);
		if ( m )
			puts("0");
		else
			if ( h==12 ) 
				printf("24\n");
			else
				printf("%d\n", (h+12)%24);
	}
	return 0;
}
