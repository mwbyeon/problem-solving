#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int n, k;
	int occur[102][10];
	memset(occur, 0, sizeof(occur));
	
	for ( int i=2 ; i<=100 ; ++i )
	{
		int k = 10;
		set<int> rem;
		do {
			rem.insert(k);
			occur[i][k/i]++;
			k = (k%i)*10;
		} while ( rem.find(k)==rem.end() && k!=0 );
	}

	while ( scanf("%d %d", &n, &k)!=EOF )
	{
		int res = 0;
		for ( int i=1 ; i<=n ; ++i )
		{
			res += occur[i][k];
		}
		printf("%d\n", res);
	}
	return 0;
}
