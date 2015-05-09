#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

map<int,int> memo;

int solve(int n)
{
	int& res = memo[n];
	if ( res ) return res;

	REP(i, 60) {
		int t = i*i*i;
		if ( t<=n ) res >?= t;
		else break;
	}
	REP(i, 100) {
		int t = i*(i+1)*(i+2)/6;
		if ( t<=n ) res >?= t;
		else break;
	}
	REP(i, 60) REP(j, 100) {
		int t = i*i*i + j*(j+1)*(j+2)/6;
		if ( t <= n ) res >?= t;
		else break;
	}
	return res;
}


int main()
{
	int n;
	while ( scanf("%d", &n), n ) 
		printf("%d\n", solve(n));
	return 0;
}



