
#include <iostream>
using namespace std;

int main()
{
	bool press[26][1000];
	int tc, t;
	int a, b, cnt, i, j;
	char alpha[] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char c;

	cin >> tc;
	while ( tc-- )
	{
		memset(press, 0, sizeof(press));
		cin >> t;
		while ( t-- )
		{
			cin >> c >> a >> b;
			for ( i=a ; i<b ; ++i )
				press[c-'A'][i] = ~press[c-'A'][i];
		}
		for ( i=0 ; i<1000 ; ++i ) {
			cnt=0;
			for ( j=0 ; j<26 ; ++j )
				if ( press[j][i] )
					++cnt;
			if ( cnt )
				cout << alpha[cnt];
				
		}
		cout << endl;
	}
	return 0;
}
				
