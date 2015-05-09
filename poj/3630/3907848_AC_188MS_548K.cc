#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void *a, const void *b) {
	return strcmp((char*)a, (char*)b);
}

int main()
{
	int T;
	char list[10001][16];

	scanf("%d", &T);
	while ( T-- ) {
		int n, num;
		scanf("%d", &n);
		for ( int i=0 ; i<n ; ++i ) scanf("%s", list[i]);
//		sort(list, list+n, cmp);
		qsort(list, n, 16, cmp);

		int res = true;
		for ( int i=1 ; i<n ; ++i ) {
			int len = strlen(list[i-1]); // = list[i-1].length();
			bool flag = false;
			for ( int j=0 ; j<len ; ++j ) if ( list[i-1][j] != list[i][j] ) {
				flag = true;
				break;
			}
			if ( !flag ) {
				res = false;
				break;
			}
		}

		if ( res ) puts("YES"); else puts("NO");
	}
	return 0;
}

