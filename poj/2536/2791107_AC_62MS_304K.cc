#include <iostream>
#include <memory>
#include <cstdio>
#include <memory>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define CLR(a,n) memset(a,n,sizeof(a))

int n, m, s, v;
int match[102];
bool seen[102];
double gopher[102][2], hole[102][2];

double dist(int u, int v) {
	double dx = gopher[u][0]-hole[v][0];
	double dy = gopher[u][1]-hole[v][1];
	return sqrt(dx*dx+dy*dy);
}

bool dfs(int u) {
	if ( seen[u] ) return false;
	seen[u] = true;
	REP(i, m) if ( dist(u,i)<1.*s*v ) {
		if ( match[i]==-1 || dfs(match[i]) ) {
			match[i] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	while ( scanf("%d %d %d %d", &n, &m, &s, &v)!=EOF ) {
		CLR(match,-1);
		REP(i, n) scanf("%lf %lf", &gopher[i][0], &gopher[i][1]);
		REP(i, m) scanf("%lf %lf", &hole[i][0], &hole[i][1]);

		int safe = 0;
		REP(i, n) {
			CLR(seen,0);
			if ( dfs(i) ) safe++;
		}
		
		printf("%d\n", n-safe);
	}
	return 0;
}
