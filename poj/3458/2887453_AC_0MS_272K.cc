#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;

int main()
{
	int T;
	char str[3][102];
	int len[3], id;

	scanf("%d", &T);
	while ( T-- ) {
		memset(str, 0, sizeof(str));
		for ( int i=0 ; i<3 ; ++i ) {
			scanf("%s", str[i]);
			len[i] = strlen(str[i]);
		}

		id = 0;
		for ( int i=0 ; i<len[1] ; ++i ) 
			if ( str[1][i]=='*' || str[0][id]==str[1][i] || str[0][id]==str[2][i] ) id++;
		if ( id>=len[0] ) puts("win"); else puts("lose");
	}
	return 0;
}
