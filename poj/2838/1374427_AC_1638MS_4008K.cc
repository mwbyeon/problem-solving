
#include <cstdio>
#include <cstdlib>
#include <memory>

#define MAX 1002

int graph[MAX][MAX];
int stack[MAX*MAX];
bool visit[MAX*MAX];

/*
void insert_edge(int u, int v) 
{
	
	graph[u][++graph[u][0]] = v;
	graph[v][++graph[v][0]] = u;
}

void delete_edge(int u, int v) 
{
	int i;
	for ( i=0 ; graph[u][i]!=u ; ++i );
	graph[u][i] = -1;
	
	for ( i=0 ; graph[v][i]!=v ; +i );
	graph[v][i] = -1;
}
			
bool isconnect(int u, int v)
{
	int stack[MAX]={u}, ptr=1, node, i, sz;

	if ( u==v ) return 1;
	
	while ( ptr ) {
		node = stack[--ptr];

		sz = graph[node][0]+1;
		for ( i=1 ; i<sz ; ++i ) {
			if ( graph[node][i] ) {
				if ( graph[node][i]==v )
					return 1;
				else
					stack[ptr++] = graph[node][i];
			}
		}
	}
	return 0;
}
*/

void insert_edge(int u, int v)
{
	int i;
	for ( i=0 ; graph[u][i]>0 ; ++i );
	graph[u][i] = v;

	for ( i=0 ; graph[v][i]>0 ; ++i );
	graph[v][i] = u;
}

void delete_edge(int u, int v)
{
	int i;
	for ( i=0 ; graph[u][i]!=v ; ++i );
	graph[u][i] = -1;
	
	for ( i=0 ; graph[v][i]!=u ; ++i );
	graph[v][i] = -1;
}

bool isconnect(int v1, int v2)
{
	int i,t; 
	int q[1001]={0,}; 
	int v[1001]={0,}; 
	int f,r; 

	q[1] = v1; v[v1] = 1; 
	f = 2; r = 1; 

	while(f!=r) { 
		t = q[r]; 
		if(t==v2) return 1; 

		for(i=0;graph[t][i] != 0; i++) { 
			if(graph[t][i] > 0 && !v[graph[t][i]]) { 
				v[graph[t][i]] = 1; 
				q[f++] = graph[t][i]; 
			} 
		} 

		r++; 
	} 

	return 0; 
/*
	int ptr, i, node, next;
	
	memset(visit, false, sizeof(visit));
	
	stack[0]=u;
	ptr=1;
	visit[u] = 1;
	
	while ( ptr ) {
		node = stack[--ptr];

		if ( node==v ) return true;
		
		for ( i=0 ; graph[node][i]!=0 ; ++i ) {
			next = graph[node][i];
			if ( next>0 && !visit[next] ) {
				visit[next] = true;
				stack[ptr++] = next;
			}
		}
	}
	return false;
*/
}
			

int main()
{
	int n, q;
	int u, v;
	char c;

	memset(graph, 0, sizeof(graph));
	scanf("%d %d ", &n, &q);

	while ( q-- )
	{
		scanf("%c %d %d ", &c, &u, &v);

		switch ( c ) {
			case 'I':
				insert_edge(u,v); break;
			case 'D':
				delete_edge(u,v); break;
			case 'Q':
				puts( (isconnect(u,v))?"Y":"N" ); break;
		}
	}
	return 0;
}

