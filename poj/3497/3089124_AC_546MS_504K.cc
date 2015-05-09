#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<string,int> tid;
set<int,greater<int> > candi;
vector<vector<pair<int,int> > > comps;
int ntype;
int budget;

bool possible(int q) {
	long long sum = 0;
	for ( int i=0 ; i<ntype ; ++i ) {
		int n = comps[i].size();
		int mv = INT_MAX;
		for ( int j=0 ; j<n ; ++j ) {
			if ( q <= comps[i][j].second && mv > comps[i][j].first )
				mv = comps[i][j].first;
		}
		if ( mv == INT_MAX ) return false;
		sum += mv;
		if ( sum > budget ) return false;
	}
	return true;
}

int solve() {
	set< int,greater<int> >::iterator it = candi.begin();
	for ( ; it != candi.end() ; ++it )
		if ( possible(*it) ) return *it;
	return -1;
}

int main()
{
	int T, n;
	char type[32], name[32];

	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d %d", &n, &budget);

		tid.clear();
		candi.clear();
		comps.clear();

		comps.resize(n);

		int p, q, idx = 0;
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%s %s %d %d", type, name, &p, &q);
			if ( tid.find(type)==tid.end() ) tid[type] = idx++;
			comps[tid[type]].push_back(make_pair(p,q));
			candi.insert(q);
		}
		ntype = idx;
		printf("%d\n", solve());
	}
	return 0;
}
