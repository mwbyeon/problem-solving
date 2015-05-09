// maximum bipartite matching

#include <iostream>
#include <memory>
#include <cstdio>
#include <memory>
#include <cmath>
using namespace std;

#define REP(i,n) for(i=0;i<n;++i)
#define CLR(a,n) memset(a,n,sizeof(a))

int n, m, s, v;
int match[101];
bool seen[101];
double gopher[101][2], hole[101][2];
double maxl;

double dist(int u, int v) {
	double dx = gopher[u][0]-hole[v][0];
	double dy = gopher[u][1]-hole[v][1];
	return sqrt(dx*dx+dy*dy);
}

bool dfs(int u) {
	int i;
	if ( seen[u] ) return false;
	seen[u] = true;
	REP(i, m) if ( dist(u,i)<maxl ) {
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
		int safe = 0, i;
		CLR(match,-1);
		maxl = 1.*s*v;
		REP(i, n) scanf("%lf %lf", &gopher[i][0], &gopher[i][1]);
		REP(i, m) scanf("%lf %lf", &hole[i][0], &hole[i][1]);

		REP(i, n) {
			CLR(seen,0);
			if ( dfs(i) ) safe++;
		}
		
		printf("%d\n", n-safe);
	}
	return 0;
}
