#include <iostream>
using namespace std;

int main()
{
	int n, x;
	int deck[64], num[20];
	for ( int T=1 ; scanf("%d %d", &n, &x)!=EOF ; ++T ) {
		int k;
		for ( int i=1 ; i<=n ; ++i ) deck[i] = i;
		for ( int i=0 ; i<20 ; ++i ) scanf("%d", &num[i]);

		int remain = n;
		for ( int i=0 ; i<20 && remain!=x ; ++i ) {
			int cnt = 0;
			for ( int j=1 ; j<=n && remain!=x ; ++j ) {
				if ( deck[j]!=-1 ) {
					++cnt;
					if ( cnt%num[i]==0 ) {
						deck[j] = -1;
						remain--;
					}
				}
			}
		}

		printf("Selection #%d\n", T);
		for ( int i=1 ; i<=n ; ++i ) if ( deck[i]!=-1 ) printf("%d ", deck[i]);
		puts("\n");
	}
	return 0;
}
