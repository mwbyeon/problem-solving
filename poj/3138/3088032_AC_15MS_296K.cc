#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int s, t, m;
	int id, p, q;
	int sch[102];
	bool checked[102];
	for ( int T=1 ; scanf("%d %d %d", &s, &t, &m), s ; ++T ) {
		memset(sch, 0, sizeof(sch));
		memset(checked, 0, sizeof(checked));
		for ( int i=0 ; i<s ; ++i ) {
			scanf("%d %d %d", &id, &p, &q);
			sch[id] += p+q;
		}
		for ( int i=0 ; i<t ; ++i ) {
			scanf("%d %d", &id, &p);
			if ( !checked[id] && p>=m ) {
				checked[id] = 1;
				sch[id]++;
			}
		}
		int res = 0;
		for ( int i=1 ; i<=s ; ++i ) res += sch[i];
		printf("Case %d: %d\n", T, res);
	}
	return 0;
}
