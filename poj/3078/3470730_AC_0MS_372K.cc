#include <iostream>
using namespace std;

int main()
{
	int T;
	int n, k;
	int src, dst;
	char str[20][10];
	char *ptr[20];
	bool used[20];

	scanf("%d", &T);
	while ( T-- ) {
		memset(used, 0, sizeof(used));
		memset(ptr, 0, sizeof(ptr));

		scanf("%d %d", &n, &k);
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%s", str[i]);
		}
		for ( int i=0 ; i<k ; ++i ) {
			scanf("%d %d", &src, &dst);
			--src, --dst;
			ptr[dst] = str[src];
			used[src] = 1;
		}
		int k = 0;
		for ( int i=0 ; i<n ; ++i  ) {
			if ( !ptr[i] ) {
				while ( used[k] ) ++k;
				ptr[i] = str[k++];
			}
		}
		for ( int i=0 ; i<n ; ++i ) printf("%s ", ptr[i]);
		puts("");
	}
	return 0;
}

