#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n;
	int pay = 0;
	map<int,int> corr;
	cin >> n;
	while ( n-- ) {
		int q, a, e;
		cin >> q >> a >> e;
		if ( a==0 ) {
			pay += 10;
		}
		else {
			pay += 20;
			if ( corr[q] ) pay += 10*corr[q];
			corr[q]++;
			if ( e==1 ) pay += 20;
		}
	}
	cout << pay << endl;
}
