#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define pb push_back
#define CLR(x,n) memset(x,n,sizeof(x))

int main()
{
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n, m;
		scanf("%d %d", &n, &m);

		vector<vector<int> > heavier(n), lighter(n);
		REP(i, m) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			heavier[b].pb(a);
			lighter[a].pb(b);
		}

		int res = 0;
		REP(i, n) {
			stack<int> st;
			int cnt = 0;
			bool visited[n];
			CLR(visited, 0);
			st.push(i);
			visited[i] = true;
			while ( !st.empty() ) {
				cnt++;
				int t = st.top(); st.pop();
				FORE(it, heavier[t]) {
					int k = *it;
					if ( !visited[k] ) {
						st.push(k);
						visited[k] = true;
					}
				}
			}
			if ( cnt > (n+1)/2 ) {
				++res;
				continue;
			}
			CLR(visited, 0);
			cnt = 0;
			st.push(i);
			visited[i] = true;
			while ( !st.empty() ) {
				cnt++;
				int t = st.top(); st.pop();
				FORE(it, lighter[t]) {
					int k = *it;
					if ( !visited[k] ) {
				   		st.push(k);
						visited[k] = true;
					}
				}
			}
			if ( cnt > (n+1)/2 ) ++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
