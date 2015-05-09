#include <iostream>
#include <cstdio>
#include <memory>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define sz size()
#define pb push_back

typedef vector<int> VI;
typedef vector<VI> VVI;

int main()
{
	int K, N, M;
	cin >> K >> N >> M;

	VI cows(K);
	REP(i, K) cin >> cows[i];

	VVI conn(N+1, VI());
	REP(i, M) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].pb(b);
	}

	VI pasture(N+1, 0);
	REP(i, K) {
		stack<int> s;
		VI visited(N+1, 0);

		s.push(cows[i]);
		visited[cows[i]] = 1;
		while ( !s.empty() ) {
			int c = s.top(); s.pop();
			pasture[c]++;
			
			REP(j, conn[c].sz) {
				int t = conn[c][j];
				if ( !visited[t] ) {
					s.push(t);
					visited[t] = 1;
				}
			}
		}
	}
	cout << count(pasture.begin(), pasture.end(), K);
	return 0;
}
