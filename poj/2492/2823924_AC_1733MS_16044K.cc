#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
using namespace std;

int graph[2002][2002];
int color[2002];
bool colorable;
int n, k;

void dfs(int node, int c) {
	color[node] = c;
	for ( int i=1 ; i<=n && colorable ; ++i ) {
		if ( graph[node][i]==0 ) continue;

		if ( color[i]==-1 ) {
			//printf(" %d %d %d\n", i, c, c^1);
			dfs(i, c^1);
		}
		else {
			if ( color[i]==c ) {
				colorable = 0;
				return;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for ( int t=1 ; t<=T ; ++t ) {
		printf("Scenario #%d:\n", t);

		memset(graph, 0, sizeof(graph));
		memset(color, -1, sizeof(color));

		scanf("%d %d", &n, &k);
		for ( int i=0 ; i<k ; ++i ) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		colorable = true;

		for ( int i=1 ; i<=n ; ++i )
			if ( color[i]==-1 ) 
				dfs(i, 1);

		if ( !colorable ) 
			puts("Suspicious bugs found!\n");
		else
			puts("No suspicious bugs found!\n");
	}
	return 0;
}

