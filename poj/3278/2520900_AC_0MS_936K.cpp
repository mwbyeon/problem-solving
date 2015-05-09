#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;

#define min(x,y) x<y?x:y

int N, K;
int t[200002];

int solve() {
	int i;
	for ( i=0 ; i<N ; ++i ) t[i] = N-i;
	for ( i=N+1 ; i<=K+1 ; ++i ) {
		if ( i&1 ) t[i] = t[i-1]+1;
		else t[i] = min(t[i-1]+1, t[i/2]+1);
		if ( t[i-1] > t[i]+1 ) t[i-1] = t[i]+1;
	}
	//for ( int i=0 ; i<=K ; ++i ) printf("%d: %d \n",i, t[i]);
	return t[K];
}

int main()
{

	scanf("%d %d", &N, &K);
	memset(t, 0, sizeof(t));

	printf("%d", solve());
	return 0;
}
