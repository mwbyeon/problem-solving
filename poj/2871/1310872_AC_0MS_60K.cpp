#include <cstdio>

int main()
{
	float t1, t2;
	if ( scanf("%f", &t1), t1!=999 ) {
		while ( scanf("%f",&t2), t2!=999.0 )
		{
			printf("%.2f\n", t2-t1);
			t1=t2;
		}
	}
	puts("End of Output");
	return 0;
}
