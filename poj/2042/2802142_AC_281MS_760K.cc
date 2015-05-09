#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define CLR(x,n) memset(x,n,sizeof(x))

int table[1<<17];

int main()
{
	int sqr[182], n = 182;
	REP(i, n) sqr[i] = i*i;
	memset(table, 0, sizeof(table));
	FOR(i, 1, n) {
		++table[sqr[i]];
		FOR(j, i, n){
			++table[sqr[i]+sqr[j]];
			FOR(k, j, n) {
				++table[sqr[i]+sqr[j]+sqr[k]];
				FOR(l, k, n) {
					++table[sqr[i]+sqr[j]+sqr[k]+sqr[l]];
				}
			}
		}
	}
	while ( scanf("%d",&n), n ) 
		printf("%d\n", table[n]);
	return 0;
}
