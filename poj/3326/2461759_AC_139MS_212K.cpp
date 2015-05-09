#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef map<int, map<int,VI> > MMVI;

int main()
{
	int N, M;
	while ( scanf("%d %d", &N, &M), N && M ) {
		MMVI rec;
		int r, q;

		scanf("%d", &r);
		int t, n, m, s, i, j;
		while ( r-- ) {
			scanf("%d %d %d %d", &t, &n, &m, &s);
			rec[m][n].push_back(t);
		}
		scanf("%d", &q);
		while ( q-- ) {
			int t1, t2, mm;
			scanf("%d %d %d", &t1, &t2, &mm);
			vector<bool> loged(1280, false);
			map<int,VI>::iterator it;
			for ( it=rec[mm].begin() ; it!=rec[mm].end() ; ++it ) {
				VI& v = it->second;
				for ( i=0 ; i<v.size() ; i+=2 ) 
					for ( j=v[i] ; j<v[i+1] ; ++j ) 
						loged[j] = true;
			}
			int res = 0;
			for ( i=t1 ; i<t2 ; ++i ) if ( loged[i] ) ++res;
			printf("%d\n", res);
		}
	}
	return 0;
}
