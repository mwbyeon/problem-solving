
#include <iostream>
#include <queue>
#include <deque>
#include <utility>
#include <cstdio>
using namespace std;

#define MAX 10000

typedef pair<int,int> 			PII;
typedef queue<PII, deque<PII> > QUEUE;

bool prime[MAX];
bool visited[MAX];

void set_prime()
{
	int i, j;
	memset(prime, true, sizeof(prime));

	for ( i=4 ; i<MAX ; i+=2 )
		prime[i] = false;
	for ( i=3 ; i<MAX ; i+=2 )
		if ( prime[i] )
			for ( j=i+i ; j<MAX ; j+=i ) 
				prime[j] = false;
}

int main()
{
	set_prime();
	
	int t;
	int beg, end, cnt;
	int i, e;
	QUEUE q;
	PII p;

	cin >> t;
	while ( t-- ) {
		scanf("%d %d", &beg, &end);
		
		memset(visited, false, sizeof(prime));
		// BFS
		q.push(make_pair(beg,0));
		visited[beg] = true;
		while ( !q.empty() ) {
			p = q.front();
			q.pop();
			beg = p.first;
			cnt = p.second;
			visited[beg] = true;

			if ( beg==end ) {
				while ( !q.empty() ) q.pop();
			}
			else {
				for ( i=(beg%1000)+1000, e=10000 ; i<e ; i+=1000 )
					if ( prime[i] && !visited[i] )
						q.push(make_pair(i, cnt+1));
				for ( i=(beg%100)+beg/1000*1000, e=(beg/1000+1)*1000 ; i<e ; i+=100 )
					if ( prime[i] && !visited[i] )
						q.push(make_pair(i, cnt+1));
				for ( i=(beg%10)+beg/100*100, e=(beg/100+1)*100 ; i<e ; i+=10 )
					if ( prime[i] && !visited[i] )
						q.push(make_pair(i, cnt+1));
				for ( i=(beg/10*10), e=(beg/10+1)*10 ; i<e ; ++i )
					if ( prime[i] && !visited[i] )
						q.push(make_pair(i, cnt+1));
			}			
		}
		printf("%d\n", cnt);
	}

	return 0;
}

