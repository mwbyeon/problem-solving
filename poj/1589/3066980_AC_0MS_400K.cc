#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while ( cin >> n ) {
		vector<string> list(n);
		int maxl = 0;
		for ( int i=0 ; i<n ; ++i ) {
			cin >> list[i];
			maxl >?= list[i].length();
		}
		sort(list.begin(), list.end());

		for ( int i=0 ; i<n ; ++i ) list[i].resize(maxl+2,' ');

		cout << string(60, '-') << endl;
		int cols = 62/(maxl+2);
		int rows = n/cols + (n%cols!=0);

		//printf("rows = %d, cols = %d\n", rows, cols);
		
		vector<string> print(rows);
		for ( int i=0 ; i<n ; ++i ) print[i%rows] += list[i];

		for ( int i=0 ; i<rows ; ++i ) cout << print[i] << endl;
	}
	return 0;
}
