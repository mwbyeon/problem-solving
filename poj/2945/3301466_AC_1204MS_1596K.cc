#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m;
	char line[22];
	int res[20001];
	while ( scanf("%d %d", &n, &m), n ) {
		memset(res, 0, sizeof(res));
		map<string,int> dna;
		for ( int i=0 ; i<n ; ++i ) {
			scanf("%s", line);
			dna[line]++;
		}
		map<string,int>::iterator it = dna.begin();
		while ( it!=dna.end() ) {
			res[it->second]++;
			++it;
		}
		for ( int i=0 ; i<n ; ++i ) {
			printf("%d\n", res[i+1]);
		}
	}
	return 0;
}
