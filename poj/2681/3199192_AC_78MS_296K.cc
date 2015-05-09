#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);
	char word1[64], word2[64];
	int cnt[26];
	int len1, len2;
	for ( int t=1 ; t<=T ; ++t ) {
		gets(word1);
		gets(word2);
		len1 = strlen(word1);
		len2 = strlen(word2);
		memset(cnt, 0, sizeof(cnt));
		for ( int i=0 ; i<len1 ; ++i ) cnt[word1[i]-'a']++;
		for ( int i=0 ; i<len2 ; ++i ) cnt[word2[i]-'a']--;
		int res = 0;
		for ( int i=0 ; i<26 ; ++i ) res += abs(cnt[i]);
		printf("Case #%d:  %d\n", t, res);
	}
	return 0;
}
