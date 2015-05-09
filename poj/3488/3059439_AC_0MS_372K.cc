#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while ( cin >> n ) {
		string str;
		string line[n];
		for ( int i=0 ; i<n ; ++i ) cin >> line[i];

		for ( int i=0 ; i<line[0].length() ; ++i )
			for ( int j=0 ; j<n ; ++j )
				str += line[j][i];

		replace(str.begin(), str.end(), '_', ' ');
		replace(str.begin(), str.end(), '\\','\n');
		str = str.substr(str.find_first_not_of(' '));
		reverse(str.begin(), str.end());

		cout << str << endl << endl;
	}
	return 0;
}
