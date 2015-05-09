#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
int len[1024];

bool possible() {
	for ( int i=0 ; i<n ; i+=k ) {
		int sum = 0;
		for ( int j=0 ; j<k ; ++j ) sum += len[i+j];
		double aver = double(sum)/double(k);
		for ( int j=0 ; j<k ; ++j ) 
			if ( fabs(aver-len[i+j]) > 2.0  ) return 0;
	}
	return 1;
}

int main()
{
	for ( int T=1 ; cin >> n >> k, n || k ; ++T ) {
		string name;
		for ( int i=0 ; i<n ; ++i ) {
			cin >> name;
			len[i] = name.length();
		}
		sort(&len[0], &len[n]);
		cout << "Case " << T << ": " << (possible()?"yes":"no") << "\n\n";
	}
	return 0;
}

