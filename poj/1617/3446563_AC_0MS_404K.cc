#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string key, text;
	char plain[10][10];
	while ( cin >> key, key != "THEEND" ) {
		cin >> text;
		int keyLen = key.length();
		int textLen = text.length();

		vector< pair<char,int> > vkey;
		vkey.reserve(keyLen);
		for ( int i=0 ; i<keyLen ; ++i ) vkey.push_back(make_pair(key[i],i));
		sort(vkey.begin(), vkey.end());

		int row = textLen/keyLen;
		int k = 0;
		for ( int i=0 ; i<keyLen ; ++i ) {
			for ( int j=0 ; j<row ; ++j ) {
				plain[j][vkey[i].second] = text[k++];
			}
		}

		for ( int i=0 ; i<row ; ++i )
			for ( int j=0 ; j<keyLen ; ++j )
				printf("%c", plain[i][j]);
		puts("");
	}
	return 0;
}
