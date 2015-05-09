#include <iostream>
using namespace std;

int main()
{
	string str1, str2;
	int len1, len2;
	int cnt1[26], cnt2[26];
	while ( getline(cin, str1) && getline(cin, str2) ) {
		len1 = str1.length();
		len2 = str2.length();
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));

		for ( int i=0 ; i<len1 ; ++i ) if ( islower(str1[i]) ) ++cnt1[str1[i]-'a'];
		for ( int i=0 ; i<len2 ; ++i ) if ( islower(str2[i]) ) ++cnt2[str2[i]-'a'];

		for ( int i=0 ; i<26 ; ++i ) {
			int c = min(cnt1[i], cnt2[i]);
			for ( int j=0 ; j<c ; ++j ) printf("%c", 'a'+i);
		}
		puts("");
	}
	return 0;
}
