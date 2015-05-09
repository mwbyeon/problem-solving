#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, num[13];
	while ( scanf("%d", &n), n ) {
		vector< vector<int> > res;
		for ( int i=0 ; i<n ; ++i ) scanf("%d", &num[i]);
		for ( int i=0 ; i<(1<<n) ; ++i ) {
			vector<int> v;
			v.reserve(6);
			if ( __builtin_popcount(i)==6 ) {
				for ( int j=0 ; j<n ; ++j ) if ( i&(1<<j) ) v.push_back(num[j]);
				res.push_back(v);
			}
		}
		sort(res.begin(), res.end());
		int sz = res.size();
		for ( int i=0 ; i<sz ; ++i ) {
			for ( int j=0 ; j<6 ; ++j ) printf("%d ", res[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}

