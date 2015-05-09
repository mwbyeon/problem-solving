
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int num, rem, i=0;
	bool digit[200];
	scanf("%d", &num);
	if ( num==0 )
		printf("0");
	else {
		for ( i=1 ; num ; ++i ) {
			if ( num<0 ) {
				digit[i] = num%(-2);
				num = num/(-2)+digit[i];
//				printf("%d %d\n", num, digit[i]);
			}
			else {
				digit[i] = num%(-2);
				num = num/(-2);
//				printf("%d %d\n", num, digit[i]);
			}
		}
		while ( --i )
			printf("%d",digit[i]?1:0);
	}
	puts("");
	return 0;
}
