#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;

int main()
{
	int n, m, r;
	int cnt[10002];

	while ( scanf("%d %d", &n, &m), n ) {
		memset(cnt, 0, sizeof(cnt));

		for ( int i=0 ; i<n ; ++i ) {
			for ( int j=0 ; j<m ; ++j ) {
				scanf("%d", &r);
				cnt[r]++;
			}
		}

		VPII v;
		v.reserve(10000);
		for ( int i=1 ; i<=10000 ; ++i ) {
			if ( cnt[i] ) {
				v.push_back(make_pair(-cnt[i], i));
//				printf("%d : %d\n", i, cnt[i]);
			}
		}
		sort(v.begin(), v.end());
		int sec = -v[1].first;
		for ( int i=0 ; i<=10000 ; ++i ) if ( cnt[i]==sec ) printf("%d ", i);
		puts("");
	}
	return 0;
}
