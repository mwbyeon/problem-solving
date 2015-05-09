#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char comm[8];
	char history[101][71] = {"http://www.acm.org/"};
	char ignore[] = "Ignored";
	int idx = 0;
	while ( scanf("%s", comm), comm[0]!='Q' ) {
		switch ( comm[0] ) {
			case 'V':
				scanf("%s", history[++idx]);
				puts(history[idx]);
				history[idx+1][0] = '\0';
				break;
			case 'B':
				if ( idx == 0 ) puts(ignore);
				else puts(history[--idx]);
				break;
			case 'F':
				if ( history[idx+1][0]=='\0' ) puts(ignore);
				else puts(history[++idx]);
				break;
		}
	}
	return 0;
}
