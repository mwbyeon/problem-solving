#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for ( int t=1 ; t<=T ; ++t ) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		printf("Scenario #%d:\n", t);
		if ( (abs(a-c)+abs(b-d))%2 )
			puts("1\n");
		else
			puts("0\n");
	}
	return 0;
}


