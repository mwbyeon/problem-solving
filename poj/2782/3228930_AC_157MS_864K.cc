#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, maxlen;
	int len[100001];

	scanf("%d %d", &n, &maxlen);

	for ( int i=0 ; i<n ; ++i ) scanf("%d", &len[i]);
	sort(len, len+n, greater<int>());

	bool used[100001];
	memset(used, 0, sizeof(used));
	int res = 0;
	for ( int i=0, j=n-1 ; i<n ; ++i ) {
		if ( !used[i] ) {
			used[i] = 1;
			++res;
			if ( len[i]+len[j]<=maxlen ) {
				used[j--] = 1;
			}
		}
		else break;
	}
	printf("%d\n", res);

	return 0;
}

