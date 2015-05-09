#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int code, k, p;
	set< pair<int,int> > pq;
	while ( scanf("%d", &code), code ) {
		if ( code == 1 ) {
			scanf("%d %d", &k, &p);
			pq.insert(make_pair(p, k));
		}
		else if ( pq.empty() ) {
			puts("0");
		}
		else {
			if ( code == 2 ) {
				printf("%d\n", pq.rbegin()->second);
				pq.erase(*pq.rbegin());
			}
			else {
				printf("%d\n", pq.begin()->second);
				pq.erase(*pq.begin());
			}
		}
	}
	return 0;
}
