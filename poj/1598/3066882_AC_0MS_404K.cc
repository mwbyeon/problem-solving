#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int k, e;
	for ( int T=1 ; cin >> k >> e ; ++T ) {
		vector<string> keywords(k);
		vector<string> execuses(e);
		vector< set<string> > words(e);
		vector<int> cnt(e);

		cin.ignore(1);
		for ( int i=0 ; i<k ; ++i ) getline(cin, keywords[i]);
		sort(keywords.begin(), keywords.end());

		int maxv = -1;
		for ( int i=0 ; i<e ; ++i ) {
			getline(cin, execuses[i]);

			int len = execuses[i].length(), pos = 0;
			string tmp(execuses[i]);
			for ( int j=0 ; j<len ; ++j ) 
				if ( isupper(tmp[j]) ) 
					tmp[j] = tolower(tmp[j]);

			for ( int j=0 ; pos<len ; ) {
				for ( ; j<len && isalpha(tmp[j]) ; ++j );
				if ( binary_search(keywords.begin(), keywords.end(), tmp.substr(pos, j-pos)) )
					cnt[i]++;
				for ( ; j<len && !isalpha(tmp[j]) ; ++j );
				pos = j;
			}
			maxv >?= cnt[i];
		}

		printf("Excuse Set #%d\n", T);
		for ( int i=0 ; i<e ; ++i ) if ( cnt[i] == maxv ) cout << execuses[i] << endl;	
		puts("");
	}
	return 0;
}
