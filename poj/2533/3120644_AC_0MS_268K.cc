#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
	int n, t;
	set<int> seq;

	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i ) {
		scanf("%d", &t);
		pair<set<int>::iterator,bool> it = seq.insert(t);
		if ( it.second && ++it.first != seq.end() ) seq.erase(it.first);
	}
	printf("%d\n", seq.size());
	return 0;
}
