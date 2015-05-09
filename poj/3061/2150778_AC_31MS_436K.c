#include <stdio.h>

int main()
{
	int seq[100001];
	int t, n, s, len, min_len;
	int i, j;
	long sum;

	scanf("%d", &t);
	while ( t-- ) {
		scanf("%d %d", &n, &s);
		sum = 0;
		min_len = n;
		for ( i=j=0 ; i<n ; ++i ) {
			scanf("%d", &seq[i]);
			sum += seq[i];
			while (  i>j && sum-seq[j]>=s ) {
				sum -= seq[j++];
				len = i-j+1;
				if ( min_len>len ) min_len = len;
			}
		}
		printf("%d\n", s>0&&sum>=s?min_len:0);
	}
	return 0;
}
