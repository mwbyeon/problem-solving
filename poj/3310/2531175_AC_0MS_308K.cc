#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <stack>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define sz size()
#define pb push_back

int n, e;

bool all_connected(VVI& node) {
	vector<bool> visited(node.sz, false);
	VI parent(node.sz, 0);
	stack<int> s;

	s.push(1);
	visited[1] = true;
	while ( !s.empty() ) {
		int t = s.top(); s.pop();
		REP(i, node[t].sz) {
			if ( parent[t]!=node[t][i] ) {
				if ( visited[node[t][i]] ) return false;
				s.push(node[t][i]);
				visited[node[t][i]] = true;
				parent[node[t][i]] = t;
			}
		}
	}
	FOR(i, 1, visited.sz) if ( !visited[i] ) return false;
	return true;
}

bool is_cycle(VVI& node) {
	return false;
}

bool caterp(VVI& node) {
	if ( !all_connected(node) ) return false;
	if ( is_cycle(node) ) return false;

	FOR(i, 1, node.sz) {
		if ( node[i].empty() ) return false;
		int cnt = 0;
		REP(j, node[i].sz) if ( node[node[i][j]].sz > 2 ) cnt++;
		if ( cnt > 2 ) return false;
	}
	return true;
}

int main()
{
	for ( int T=1 ; scanf("%d %d", &n, &e), n ; ++T ) {
		VVI node(n+1, VI());
		REP(i, e) {
			int p, q;			
			scanf("%d %d", &p, &q);
			node[p].pb(q);
			node[q].pb(p);
		}
		printf("Graph %d is %sa caterpillar.\n", T, caterp(node)?"":"not ");
	}
	return 0;
}
