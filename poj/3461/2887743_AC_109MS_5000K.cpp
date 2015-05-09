#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char word[10001], text[1000001];
int table[1000001];

int main()
{
	int T;

	int wlen, tlen;
	scanf("%d ", &T);
	while ( T-- ) {
		int i, k, res;

		gets(word);
		gets(text);
		wlen = strlen(word);
		tlen = strlen(text);

		// KMP setup
		table[0] = -1;
		for ( i=1 ; i<tlen ; ++i ) {
			k = table[i-1];
			while ( k>=0 ) if ( word[k]==word[i-1] ) break; else k=table[k];
			table[i] = k+1;
		}

		// KMP scan
		res = 0;
		for ( i=0, k=0 ; i<tlen ; ) {
			if ( k==-1 ) ++i, k=0;
			else if ( text[i]==word[k] ) {
				++i, ++k;
				if ( k>=wlen ) ++res;
			}
			else k=table[k];
		}
		printf("%d\n", res);		
	}
	return 0;
}

