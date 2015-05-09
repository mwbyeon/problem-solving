#include <iostream>
using namespace std;

int main()
{
	string spam[26] = { "4", "|3", "(", "|)", "3", "|=", "6", "#", "|", "_|", "|<", "|_", "|\\/|", "|\\|", "0", "|0", "(,)", "|?", "5", "7", "|_|", "\\/", "\\/\\/","><", "-/", "2" };
	int spamlen[26] = { 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 4, 3, 1, 2, 3, 2, 1, 1, 3, 2, 4, 2, 2, 1 };
	int memo[512];
	
	string text;
	while ( cin >> text, text[0]!='e' ) {
		string msg;
		int len = text.length();
		for ( int i=0 ; i<len ; ++i ) msg += spam[text[i]-'A'];
		
		len = msg.length();
		memset(memo, 0, sizeof(memo));

		memo[0] = 1;
		for ( int i=0 ; i<len ; ++i ) {
			for ( int k=0 ; k<26 ; ++k ) {
				if ( i+spamlen[k]<=len && msg.substr(i, spamlen[k])==spam[k] ) {
					memo[i+spamlen[k]] += memo[i];
				}
			}
		}
		printf("%d\n", memo[len]);
	}
	return 0;
}
