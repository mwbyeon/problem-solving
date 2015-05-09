#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str1, str2;
	vector<int> v1(26), v2(26);
	cin >> str1 >> str2;

	for ( int i=0 ; i<str1.length() ; ++i ) v1[str1[i]-'A']++;
	for ( int i=0 ; i<str2.length() ; ++i ) v2[str2[i]-'A']++;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if ( v1 == v2 ) cout << "YES"; else cout << "NO";

	return 0;
}
