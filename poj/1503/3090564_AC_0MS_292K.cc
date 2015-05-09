#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char num[128], sum[128];
	memset(sum, 0, sizeof(sum));
	int end=0;

	while ( gets(num), strcmp(num,"0") ) {
		strrev(num);
		int len = strlen(num);
		for ( int i=0 ; i<len ; ++i ) {
			sum[i] += num[i]-'0';
			sum[i+1] += sum[i]/10;
			sum[i] %= 10;
		}
		end = -1;
		for ( int i=0 ; i<127 ; ++i ) {
			sum[i+1] += sum[i]/10;
			sum[i] %= 10;
			if ( sum[i] ) end = i;
		}
	}
	for ( int i=end ; i>=0 ; --i ) printf("%d", sum[i]);
	puts("");
	return 0;
}
