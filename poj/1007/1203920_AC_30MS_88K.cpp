
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int>	pSI;
typedef vector<pSI>			vpSI;

int op(pSI d1, pSI d2)
{
	return d1.second < d2.second;
}

int main()
{
	int n, m, i, j, k, cnt;
	vpSI list;
	string dna;
	
	cin >> n >> m;

	list.reserve(m);
	
	for ( i=0 ; i<m ; ++i ) {
		cin >> dna;
		
		cnt = 0;
		for ( j=0 ; j<n ; ++j )
			for ( k=j+1 ; k<n ; ++k )
				if ( dna[j]>dna[k] )
					cnt++;
		list.push_back(make_pair(dna,cnt));
	}

	sort(list.begin(), list.end(), op);
	
	for ( i=0 ; i<m ; ++i )
		cout << list[i].first << endl;
		
	return 0;
}
