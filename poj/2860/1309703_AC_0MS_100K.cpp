#include <iostream>
using namespace std;

int main()
{
	int n, m, k, res=0, i;
	int final[31], initial[31];
	
	cin >> n >> m >> k;
	
	for ( i=0 ; i<k ; ++i )
		cin >> initial[i];
	

	for ( i=0 ; i<k ; ++i ) {
		cin >> final[i];
		if ( final[i]>initial[i] )
			res += (final[i]-initial[i])<<1;
		else
			res += final[i]-initial[i];
	}
	cout << res << endl;
	return 0;
}
