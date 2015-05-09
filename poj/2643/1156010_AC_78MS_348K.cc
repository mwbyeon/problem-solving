#include <iostream>
#include <string>
using namespace std;

typedef struct {
	string partyName;
	string candidate;
	int count;
} Election;

int main()
{
	int n, m, i, j, maxIdx=0;
	string line;

	cin >> n;
	getline(cin, line);

	Election elec[n];

	for ( i=0 ; i<n ; ++i )
	{
		getline(cin, elec[i].candidate);
		getline(cin, elec[i].partyName);
		elec[i].count = 0;
	}

	cin >> m;
	getline (cin, line);
	for ( i=0 ; i<m ; ++i ) 
	{
		getline(cin, line);
		for ( j=0 ; j<n && line!=elec[j].candidate ; ++j );
		if ( j<n ) {
			elec[j].count++;
			if ( elec[j].count > elec[maxIdx].count )
				maxIdx = j;
		}
	}
	int cnt = 0;
	for ( i=0 ; i<n ; ++i )
		if ( elec[i].count == elec[maxIdx].count )
			++cnt;

	if ( cnt!=1 ) 
		cout << "tie" << endl;
	else 
		cout << elec[maxIdx].partyName << endl;

	return 0;
}


