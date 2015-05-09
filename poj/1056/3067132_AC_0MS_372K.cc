#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	for ( int T=1 ; cin >> str, str[0]!='9' ; ++T ) {
		vector<string> codes;
		codes.push_back(str);
		while ( cin >> str, str[0]!='9' ) codes.push_back(str);

		sort(codes.begin(), codes.end());
		bool res = true;
		for ( int i=1 ; i<codes.size() ; ++i )
			if ( codes[i].find(codes[i-1])==0 ) res = false;

		printf("Set %d is %simmediately decodable\n", T, res?"":"not ");
	}
	return 0;
}
